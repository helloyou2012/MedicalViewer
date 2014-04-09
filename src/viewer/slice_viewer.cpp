#include "slice_viewer.h"

#include <QLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfoList>
#include <QApplication>
#include <QDir>
#include <vtkMatrix4x4.h>

#include <vtkImageMapToWindowLevelColors.h>
#include <vtkImageShiftScale.h>
#include <itkMinimumMaximumImageCalculator.h>
#include <itkStatisticsImageFilter.h>
#include "../main/global.h"

#include <sstream>

using namespace MedicalViewer;
using namespace std;


SliceViewer::SliceViewer(QWidget *parent) :QWidget(parent) {
    QVBoxLayout *vboxLayout=new QVBoxLayout(this);
    vboxLayout->setMargin(0);
    vboxLayout->setSpacing(0);
    this->createHorizontalGroupBox();
    vboxLayout->addWidget(horizontalGroupBox);

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setMargin(5);

    spanSlider = new QxtSpanSlider(this);
    layout->addWidget(spanSlider);

    viewer = new  QVTKWidget(this);
    layout->addWidget(viewer);

    ImageViewer = vtkSmartPointer<vtkImageViewer2>::New();


    // usage hint message
    usageTextProp = vtkSmartPointer<vtkTextProperty>::New();
    usageTextProp->SetFontFamilyToCourier();
    usageTextProp->SetFontSize(12);
    usageTextProp->SetVerticalJustificationToBottom();
    usageTextProp->SetJustificationToLeft();

    usageTextMapper = vtkSmartPointer<vtkTextMapper>::New();
    usageTextMapper->SetInput("Lower: Upper: Slice:");
    usageTextMapper->SetTextProperty(usageTextProp);

    usageTextActor = vtkSmartPointer<vtkActor2D>::New();
    usageTextActor->SetMapper(usageTextMapper);
    usageTextActor->GetPositionCoordinate()->SetCoordinateSystemToNormalizedDisplay();
    usageTextActor->GetPositionCoordinate()->SetValue( 0.02, 0.02);

    ImageViewer->GetRenderer()->AddActor2D(usageTextActor);

    scrollBar = new QScrollBar(Qt::Vertical, this);
    layout->addWidget(scrollBar);

    vboxLayout->addLayout(layout);

    connect(spanSlider, SIGNAL(spanChanged(int, int)), this, SLOT(setLevelAndWindow(int, int)));
    connect(scrollBar, SIGNAL(valueChanged(int)), this, SLOT(setActiveSlice(int)));

    updateImage();
}

SliceViewer::~SliceViewer() {

}

void SliceViewer::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr(""));
    horizontalGroupBox->setStyleSheet(Global::GROUPSTYLESHEET);
    QHBoxLayout *layout = new QHBoxLayout;

    openButton = new QPushButton(trUtf8("载入图片"));
    openButton->setStyleSheet(Global::BUTTONSTYLESHEET);
    connect(openButton, SIGNAL(clicked()), this, SLOT(slotLoadImage()));
    layout->addWidget(openButton);

    filterButton = new QPushButton(trUtf8("滤波处理"));
    filterButton->setStyleSheet(Global::BUTTONSTYLESHEET);
    layout->addWidget(filterButton);

    horizontalGroupBox->setLayout(layout);
}

void SliceViewer::convertImageToVTK() {
    connector = itk::ImageToVTKImageFilter<itk::Image<float, 3> >::New();
    connector->SetInput(image.getModifiedImage());
    connector->Update();
    imageVTK = connector->GetOutput();

    // create an image viewer
    ImageViewer->SetInput(imageVTK);
    ImageViewer->SetupInteractor(viewer->GetRenderWindow()->GetInteractor());
    viewer->SetRenderWindow(ImageViewer->GetRenderWindow());
    ImageViewer->GetRenderer()->ResetCamera();

    // adjust the color window and level
    itk::MinimumMaximumImageCalculator<itk::Image<float, 3> >::Pointer calculator;
    calculator = itk::MinimumMaximumImageCalculator<itk::Image<float, 3> >::New();
    calculator->SetImage(image.getModifiedImage());
    calculator->Compute();
    const unsigned int minColor = calculator->GetMinimum();
    const unsigned int maxColor = calculator->GetMaximum();

    spanSlider->setMinimum(minColor);
    spanSlider->setMaximum(maxColor);
    spanSlider->setLowerValue(minColor);
    spanSlider->setUpperValue(maxColor);
    spanSlider->setVisible(true);

    ImageViewer->SetColorLevel((maxColor + minColor) / 2);
    ImageViewer->SetColorWindow(maxColor - minColor);
}

void SliceViewer::setLevelAndWindow(int lower, int upper){
    ImageViewer->SetColorLevel((upper + lower) / 2);
    ImageViewer->SetColorWindow(upper - lower);
    updateUsageText();
    ImageViewer->Render();
}

void SliceViewer::setActiveSlice(int active) {
    updateUsageText();
    ImageViewer->SetSlice(active-1);
}

void SliceViewer::updateUsageText(){
    std::stringstream tmp;

    tmp<<"Lower:"<<spanSlider->lowerValue()<<"/"<<spanSlider->minimum()<<" "
       <<"Upper:"<<spanSlider->upperValue()<<"/"<<spanSlider->maximum()<<" "
      <<"Slice:"<<scrollBar->value()<<"/"<<image.getNbSlices();

    usageTextMapper->SetInput(tmp.str().c_str());
}

void SliceViewer::updateImage()
{
    if (image.isLoaded()) {
        scrollBar->setMinimum(1);
        scrollBar->setMaximum(image.getNbSlices());
        scrollBar->setValue(1);
        scrollBar->setVisible(true);

        convertImageToVTK();
        ImageViewer->Render();
    }
    else {
        // reset scrollbar and spanSlider
        scrollBar->setMaximum(0);
        scrollBar->setMinimum(0);
        scrollBar->setVisible(false);

        spanSlider->setMaximum(0);
        spanSlider->setMinimum(0);
        spanSlider->setVisible(false);
    }
}

void SliceViewer::slotLoadImage()
{
    QDir dir("Dir");
    dir=QFileDialog::getExistingDirectory(0,"Select Folder: ");
    QFileInfoList list = dir.entryInfoList(QDir::Dirs| QDir::Files | QDir::NoDotAndDotDot);
    std::vector<std::string> names;
    string suffix;
    foreach(QFileInfo finfo, list){
        std::string str=dir.path().toStdString().c_str();
        str=str+"/";
        names.push_back(str+finfo.fileName().toStdString().c_str());
        suffix=finfo.suffix().toStdString();
    }

    if(!names.empty()){
        QApplication::setOverrideCursor(Qt::WaitCursor);

        if (image.loadImage(names, suffix)) {
            updateImage();
            QApplication::restoreOverrideCursor();
        }else {
            QMessageBox::warning(this, "Recent Files", QString("Cannot load files!"));
            QApplication::restoreOverrideCursor();
        }
    }
}
