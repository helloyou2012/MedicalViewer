#ifndef VOLUME_VIEWER_H
#define VOLUME_VIEWER_H

#include <QWidget>
// VTK includes
#include "vtkBoxWidget.h"
#include "vtkCamera.h"
#include "vtkCommand.h"
#include "vtkColorTransferFunction.h"
#include "vtkDICOMImageReader.h"
#include "vtkImageData.h"
#include "vtkImageResample.h"
#include "vtkMetaImageReader.h"
#include "vtkPiecewiseFunction.h"
#include "vtkPlanes.h"
#include "vtkProperty.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkVolume.h"
#include "vtkVolumeProperty.h"
#include "vtkXMLImageDataReader.h"
#include "vtkFixedPointVolumeRayCastMapper.h"

#define VTI_FILETYPE 1
#define MHA_FILETYPE 2

// Forward Qt class declarations
class Ui_VolumeViewer;

namespace MedicalViewer {

class VolumeViewer : public QWidget {
Q_OBJECT
public:
    VolumeViewer(QWidget * parent = 0);
    ~VolumeViewer();
    void loadLiver(const char *dirname);
    void loadGall(const char *dirname);
    void loadVessel(const char *dirname);

public Q_SLOTS:
    virtual void loadLiverImage();
    virtual void loadGallImage();
    virtual void loadVesselImage();

private:
  // Designer form
  Ui_VolumeViewer *ui;
  vtkSmartPointer<vtkRenderer> renderer;
};
}

#endif // VOLUME_VIEWER_H
