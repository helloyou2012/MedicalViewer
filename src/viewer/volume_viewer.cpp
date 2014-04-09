#include "ui_volume_viewer.h"
#include "volume_viewer.h"

#include <QFileDialog>
#include <QDir>
#include <QLayout>
#include "../main/global.h"

using namespace MedicalViewer;
using namespace std;


VolumeViewer::VolumeViewer(QWidget *parent) :QWidget(parent) {
    this->ui = new Ui_VolumeViewer;
    this->ui->setupUi(this);
    this->ui->groupBox->setStyleSheet(Global::GROUPSTYLESHEET);

    this->ui->loadLiverBtn->setStyleSheet(Global::BUTTONSTYLESHEET);
    this->ui->loadGallBtn->setStyleSheet(Global::BUTTONSTYLESHEET);
    this->ui->loadVesselBtn->setStyleSheet(Global::BUTTONSTYLESHEET);

    connect(this->ui->loadLiverBtn, SIGNAL(clicked()), this, SLOT(loadLiverImage()));
    connect(this->ui->loadGallBtn, SIGNAL(clicked()), this, SLOT(loadGallImage()));
    connect(this->ui->loadVesselBtn, SIGNAL(clicked()), this, SLOT(loadVesselImage()));

    // Create the renderer, renderer window and interactor
    vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
    this->ui->ivtkWidget->SetRenderWindow(renWin);

    renderer = vtkSmartPointer<vtkRenderer>::New();
    this->ui->ivtkWidget->GetInteractor()->SetRenderWindow(this->ui->ivtkWidget->GetRenderWindow());
    vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
    this->ui->ivtkWidget->GetInteractor()->SetInteractorStyle(style);
    this->ui->ivtkWidget->GetInteractor()->GetInteractorStyle()->SetDefaultRenderer(renderer);

    this->ui->ivtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

VolumeViewer::~VolumeViewer() {

}

void VolumeViewer::loadLiver(const char *dirname){
    vtkSmartPointer<vtkDICOMImageReader> dicomReader = vtkSmartPointer<vtkDICOMImageReader>::New();
    dicomReader->SetDirectoryName(dirname);
    dicomReader->SetDataByteOrderToLittleEndian();
    dicomReader->Update();

    // Create our volume and mapper
    vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();
    vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> mapper = vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
    mapper->SetInputConnection( dicomReader->GetOutputPort() );

    // Create our transfer function
    vtkSmartPointer<vtkColorTransferFunction> colorFun = vtkSmartPointer<vtkColorTransferFunction>::New();
    vtkSmartPointer<vtkPiecewiseFunction> opacityFun = vtkSmartPointer<vtkPiecewiseFunction>::New();

    // Create the property and attach the transfer functions
    vtkSmartPointer<vtkVolumeProperty> property = vtkSmartPointer<vtkVolumeProperty>::New();
    property->SetIndependentComponents(true);
    property->SetColor( colorFun );
    property->SetScalarOpacity( opacityFun );
    property->SetInterpolationTypeToLinear();

    // connect up the volume to the property and the mapper
    volume->SetProperty( property );
    volume->SetMapper( mapper );

    //Skin
    colorFun->AddRGBPoint( -3024, 0, 0, 0, 0.5, 0.0 );
    colorFun->AddRGBPoint( -1000, .62, .36, .18, 0.5, 0.0 );
    colorFun->AddRGBPoint( -500, .88, .60, .29, 0.33, 0.45 );
    colorFun->AddRGBPoint( 3071, .83, .66, 1, 0.5, 0.0 );

    opacityFun->AddPoint(-3024, 0, 0.5, 0.0 );
    opacityFun->AddPoint(-1000, 0, 0.5, 0.0 );
    opacityFun->AddPoint(-500, 1.0, 0.33, 0.45 );
    opacityFun->AddPoint(3071, 1.0, 0.5, 0.0);

    mapper->SetBlendModeToComposite();
    property->ShadeOn();
    property->SetAmbient(0.1);
    property->SetDiffuse(0.9);
    property->SetSpecular(0.2);
    property->SetSpecularPower(10.0);
    property->SetScalarOpacityUnitDistance(0.8919);

    // Add the volume to the scene
    renderer->AddVolume( volume );
    //renderer->SetBackground(1,1,1);
    renderer->ResetCamera();
    // interact with data
    this->ui->ivtkWidget->GetRenderWindow()->Render();
}

void VolumeViewer::loadLiverImage(){
    QDir dir("Dir");
    dir=QFileDialog::getExistingDirectory(0,"Select Folder: ");
    if(dir.exists()){
        std::string str=dir.path().toStdString().c_str();
        str=str+"/";
        this->loadLiver(str.c_str());
    }
}
void VolumeViewer::loadGallImage(){
    QDir dir("Dir");
    dir=QFileDialog::getExistingDirectory(0,"Select Folder: ");
    if(dir.exists()){
        std::string str=dir.path().toStdString().c_str();
        str=str+"/";
        this->loadGall(str.c_str());
    }
}

void VolumeViewer::loadGall(const char *dirname){
    vtkSmartPointer<vtkDICOMImageReader> dicomReader = vtkSmartPointer<vtkDICOMImageReader>::New();
    dicomReader->SetDirectoryName(dirname);
    dicomReader->SetDataByteOrderToLittleEndian();
    dicomReader->Update();

    // Create our volume and mapper
    vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();
    vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> mapper = vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
    mapper->SetInputConnection( dicomReader->GetOutputPort() );

    // Create our transfer function
    vtkSmartPointer<vtkColorTransferFunction> colorFun = vtkSmartPointer<vtkColorTransferFunction>::New();
    vtkSmartPointer<vtkPiecewiseFunction> opacityFun = vtkSmartPointer<vtkPiecewiseFunction>::New();

    // Create the property and attach the transfer functions
    vtkSmartPointer<vtkVolumeProperty> property = vtkSmartPointer<vtkVolumeProperty>::New();
    property->SetIndependentComponents(true);
    property->SetColor( colorFun );
    property->SetScalarOpacity( opacityFun );
    property->SetInterpolationTypeToLinear();

    // connect up the volume to the property and the mapper
    volume->SetProperty( property );
    volume->SetMapper( mapper );

    //Bone
    colorFun->AddRGBPoint( -3024, 0, 0, 0, 0.5, 0.0 );
    colorFun->AddRGBPoint( -16, 0.73, 0.25, 0.30, 0.49, .61 );
    colorFun->AddRGBPoint( 641, .90, .82, .56, .5, 0.0 );
    colorFun->AddRGBPoint( 3071, 1, 1, 1, .5, 0.0 );

    opacityFun->AddPoint(-3024, 0, 0.5, 0.0 );
    opacityFun->AddPoint(-16, 0, .49, .61 );
    opacityFun->AddPoint(641, .72, .5, 0.0 );
    opacityFun->AddPoint(3071, .71, 0.5, 0.0);

    mapper->SetBlendModeToComposite();
    property->ShadeOn();
    property->SetAmbient(0.1);
    property->SetDiffuse(0.9);
    property->SetSpecular(0.2);
    property->SetSpecularPower(10.0);
    property->SetScalarOpacityUnitDistance(0.8919);

    // Add the volume to the scene
    renderer->AddVolume( volume );
    //renderer->SetBackground(1,1,1);
    renderer->ResetCamera();
    // interact with data
    this->ui->ivtkWidget->GetRenderWindow()->Render();
}
void VolumeViewer::loadVesselImage(){
    QDir dir("Dir");
    dir=QFileDialog::getExistingDirectory(0,"Select Folder: ");
    if(dir.exists()){
    std::string str=dir.path().toStdString().c_str();
    str=str+"/";
    this->loadVessel(str.c_str());
    }
}

void VolumeViewer::loadVessel(const char * dirname){
    vtkSmartPointer<vtkDICOMImageReader> dicomReader = vtkSmartPointer<vtkDICOMImageReader>::New();
    dicomReader->SetDirectoryName(dirname);
    dicomReader->SetDataByteOrderToLittleEndian();
    dicomReader->Update();

    // Create our volume and mapper
    vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();
    vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> mapper = vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
    mapper->SetInputConnection( dicomReader->GetOutputPort() );

    // Create our transfer function
    vtkSmartPointer<vtkColorTransferFunction> colorFun = vtkSmartPointer<vtkColorTransferFunction>::New();
    vtkSmartPointer<vtkPiecewiseFunction> opacityFun = vtkSmartPointer<vtkPiecewiseFunction>::New();

    // Create the property and attach the transfer functions
    vtkSmartPointer<vtkVolumeProperty> property = vtkSmartPointer<vtkVolumeProperty>::New();
    property->SetIndependentComponents(true);
    property->SetColor( colorFun );
    property->SetScalarOpacity( opacityFun );
    property->SetInterpolationTypeToLinear();

    // connect up the volume to the property and the mapper
    volume->SetProperty( property );
    volume->SetMapper( mapper );

    //Muscle
    colorFun->AddRGBPoint( -3024, 0, 0, 0, 0.5, 0.0 );
    colorFun->AddRGBPoint( -155, .55, .25, .15, 0.5, .92 );
    colorFun->AddRGBPoint( 217, .88, .60, .29, 0.33, 0.45 );
    colorFun->AddRGBPoint( 420, 1, .94, .95, 0.5, 0.0 );
    colorFun->AddRGBPoint( 3071, .83, .66, 1, 0.5, 0.0 );

    opacityFun->AddPoint(-3024, 0, 0.5, 0.0 );
    opacityFun->AddPoint(-155, 0, 0.5, 0.92 );
    opacityFun->AddPoint(217, .68, 0.33, 0.45 );
    opacityFun->AddPoint(420,.83, 0.5, 0.0);
    opacityFun->AddPoint(3071, .80, 0.5, 0.0);

    mapper->SetBlendModeToComposite();
    property->ShadeOn();
    property->SetAmbient(0.1);
    property->SetDiffuse(0.9);
    property->SetSpecular(0.2);
    property->SetSpecularPower(10.0);
    property->SetScalarOpacityUnitDistance(0.8919);

    // Add the volume to the scene
    renderer->AddVolume( volume );
    //renderer->SetBackground(1,1,1);
    renderer->ResetCamera();
    // interact with data
    this->ui->ivtkWidget->GetRenderWindow()->Render();
}
