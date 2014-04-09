#ifndef PLANE_VIEWER_H
#define PLANE_VIEWER_H

#include "vtkSmartPointer.h"
#include "vtkResliceImageViewer.h"
#include "vtkImagePlaneWidget.h"
#include "vtkDistanceWidget.h"
#include "vtkResliceImageViewerMeasurements.h"

#include <QWidget>

// Forward Qt class declarations
class Ui_PlaneViewer;

namespace MedicalViewer {

class PlaneViewer : public QWidget {
Q_OBJECT
public:
    PlaneViewer(QWidget * parent = 0);
    ~PlaneViewer();
    void loadImages(const char * dictName);

public slots:

  virtual void resliceMode(int);
  virtual void thickMode(int);
  virtual void SetBlendModeToMaxIP();
  virtual void SetBlendModeToMinIP();
  virtual void SetBlendModeToMeanIP();
  virtual void SetBlendMode(int);
  virtual void ResetViews();
  virtual void Render();
  virtual void AddDistanceMeasurementToView1();
  virtual void AddDistanceMeasurementToView( int );
  virtual void slotLoadImage();

protected:

  vtkSmartPointer< vtkResliceImageViewer > riw[3];
  vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
  vtkSmartPointer< vtkDistanceWidget > DistanceWidget[3];
  vtkSmartPointer< vtkResliceImageViewerMeasurements > ResliceMeasurements;

private:
  // Designer form
  Ui_PlaneViewer *ui;

};
}

#endif // PLANE_VIEWER_H
