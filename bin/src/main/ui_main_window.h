/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created: Mon Jan 6 20:02:10 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TechMedViewer
{
public:
    QAction *actionLoadImage;
    QAction *actionExit;
    QAction *actionHelp;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuFilters;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TechMedViewer)
    {
        if (TechMedViewer->objectName().isEmpty())
            TechMedViewer->setObjectName(QString::fromUtf8("TechMedViewer"));
        TechMedViewer->resize(659, 456);
        TechMedViewer->setIconSize(QSize(22, 22));
        actionLoadImage = new QAction(TechMedViewer);
        actionLoadImage->setObjectName(QString::fromUtf8("actionLoadImage"));
        actionLoadImage->setEnabled(true);
        actionExit = new QAction(TechMedViewer);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionHelp = new QAction(TechMedViewer);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralwidget = new QWidget(TechMedViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        TechMedViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TechMedViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 659, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFilters = new QMenu(menubar);
        menuFilters->setObjectName(QString::fromUtf8("menuFilters"));
        TechMedViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(TechMedViewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TechMedViewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuFilters->menuAction());
        menuFile->addAction(actionLoadImage);
        menuFile->addSeparator();
        menuFile->addAction(actionHelp);
        menuFile->addAction(actionExit);

        retranslateUi(TechMedViewer);

        QMetaObject::connectSlotsByName(TechMedViewer);
    } // setupUi

    void retranslateUi(QMainWindow *TechMedViewer)
    {
        TechMedViewer->setWindowTitle(QApplication::translate("TechMedViewer", "TechMed viewer", 0, QApplication::UnicodeUTF8));
        actionLoadImage->setText(QApplication::translate("TechMedViewer", "Load image...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLoadImage->setToolTip(QApplication::translate("TechMedViewer", "Load image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLoadImage->setShortcut(QApplication::translate("TechMedViewer", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("TechMedViewer", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("TechMedViewer", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("TechMedViewer", "Help", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("TechMedViewer", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("TechMedViewer", "File", 0, QApplication::UnicodeUTF8));
        menuFilters->setTitle(QApplication::translate("TechMedViewer", "Filters", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TechMedViewer: public Ui_TechMedViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
