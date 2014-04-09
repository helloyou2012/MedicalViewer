#include "main_window.h"
#include <QtGui>

using namespace MedicalViewer;
using namespace std;

MainWindow::MainWindow()
{
    menuWidget = new QListWidget;
    menuWidget->setViewMode(QListView::IconMode);
    menuWidget->setIconSize(QSize(64, 64));
    menuWidget->setMovement(QListView::Static);
    menuWidget->setMaximumWidth(70);
    menuWidget->setStyleSheet(Global::LISTSTYLESHEET);
    menuWidget->setSpacing(0);

    sliceViewer=new SliceViewer(this);
    planeViewer=new PlaneViewer(this);
    volumeViewer=new VolumeViewer(this);

    viewerWidget = new QStackedWidget;
    viewerWidget->addWidget(sliceViewer);
    viewerWidget->addWidget(planeViewer);
    viewerWidget->addWidget(volumeViewer);

    createIcons();
    menuWidget->setCurrentRow(0);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(menuWidget);
    mainLayout->addWidget(viewerWidget, 1);
    mainLayout->setMargin(0);
    setLayout(mainLayout);

    setWindowTitle(Global::APPName);
    int x=(QApplication::desktop()->width() - this->width())/2;
    int y=(QApplication::desktop()->height() - this->height())/2;
    move(x,y);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createIcons()
{
    QListWidgetItem *sliceButton = new QListWidgetItem(menuWidget);
    sliceButton->setIcon(QIcon(Global::SliceIcon));
    sliceButton->setToolTip(trUtf8("片层查看"));
    sliceButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *planeButton = new QListWidgetItem(menuWidget);
    planeButton->setIcon(QIcon(Global::PlaneIcon));
    planeButton->setToolTip(trUtf8("切割查看"));
    planeButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *volumeButton = new QListWidgetItem(menuWidget);
    volumeButton->setIcon(QIcon(Global::VolumeIcon));
    volumeButton->setToolTip(trUtf8("三维可视化"));
    volumeButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(menuWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}

void MainWindow::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;
    viewerWidget->setCurrentIndex(menuWidget->row(current));
    this->update();
}

void MainWindow::closeEvent(QCloseEvent *e){
    int result=QMessageBox::question(this,trUtf8("提示"),trUtf8("是否退出程序？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
    if(result==QMessageBox::Ok)
        e->accept();
    else
        e->ignore();
}
