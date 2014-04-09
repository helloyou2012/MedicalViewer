#include <QtGui/QApplication>
#include "main_window.h"
#include <QObject>

using namespace MedicalViewer;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.setVisible(true);
    //w.setFixedSize(800,600);
    w.setMinimumSize(800,600);
    return app.exec();
}
