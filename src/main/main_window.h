#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QFrame>
#include "global.h"
#include "../core/TMImage.h"
#include "../viewer/slice_viewer.h"
#include "../viewer/plane_viewer.h"
#include "../viewer/volume_viewer.h"

QT_BEGIN_NAMESPACE
class QListWidget;
class QListWidgetItem;
class QStackedWidget;
QT_END_NAMESPACE

namespace MedicalViewer {

class MainWindow : public QFrame
{
    Q_OBJECT

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    void createIcons();

    TMImage currentImage;
    QListWidget *menuWidget;
    QStackedWidget *viewerWidget;

    SliceViewer *sliceViewer;
    PlaneViewer *planeViewer;
    VolumeViewer *volumeViewer;

public:
    MainWindow();
    ~MainWindow();

protected:
    virtual void closeEvent(QCloseEvent *);
};

}
#endif // MAIN_WINDOW_H
