#ifndef SLICE_VIEWER_H
#define SLICE_VIEWER_H

#include <QWidget>
#include <QVTKWidget.h>
#include <QLabel>
#include <QScrollBar>
#include <QGroupBox>
#include <QPushButton>

#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkImageActor.h>
#include <vtkImageViewer2.h>
#include <vtkActor2D.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>

#include "../contrib/itkImageToVTKImageFilter.h"
#include "../core/TMImage.h"
#include "../qxt/qxtspanslider.h"

namespace MedicalViewer {

class SliceViewer : public QWidget {
Q_OBJECT
public:
    SliceViewer(QWidget * parent = 0);
    ~SliceViewer();

    QPushButton *openButton;
    QPushButton *filterButton;

public Q_SLOTS:
    void updateImage();
    void setLevelAndWindow(int lower, int upper);
    void setActiveSlice(int active);
    void updateUsageText();
    virtual void slotLoadImage();

private:
    vtkSmartPointer<vtkImageViewer2> ImageViewer;
    vtkSmartPointer<vtkTextProperty> usageTextProp;
    vtkSmartPointer<vtkTextMapper> usageTextMapper;
    vtkSmartPointer<vtkActor2D> usageTextActor;

    QVTKWidget * viewer;
    QScrollBar * scrollBar;
    QxtSpanSlider *spanSlider;
    QGroupBox *horizontalGroupBox;

    TMImage image;

    itk::ImageToVTKImageFilter<itk::Image<float, 3> >::Pointer connector;
    vtkSmartPointer<vtkImageData> imageVTK;

    void convertImageToVTK();
    void createHorizontalGroupBox();
};
}

#endif // SLICE_VIEWER_H
