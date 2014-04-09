/********************************************************************************
** Form generated from reading UI file 'volume_viewer.ui'
**
** Created: Tue Jan 7 07:43:00 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUME_VIEWER_H
#define UI_VOLUME_VIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VolumeViewer
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QPushButton *loadLiverBtn;
    QPushButton *loadGallBtn;
    QPushButton *loadVesselBtn;
    QVTKWidget *ivtkWidget;

    void setupUi(QWidget *VolumeViewer)
    {
        if (VolumeViewer->objectName().isEmpty())
            VolumeViewer->setObjectName(QString::fromUtf8("VolumeViewer"));
        VolumeViewer->resize(615, 474);
        verticalLayout_2 = new QVBoxLayout(VolumeViewer);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(VolumeViewer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        groupBox->setMaximumSize(QSize(16777215, 50));
        loadLiverBtn = new QPushButton(groupBox);
        loadLiverBtn->setObjectName(QString::fromUtf8("loadLiverBtn"));
        loadLiverBtn->setGeometry(QRect(20, 10, 100, 32));
        loadLiverBtn->setMinimumSize(QSize(100, 32));
        loadLiverBtn->setMaximumSize(QSize(100, 32));
        loadGallBtn = new QPushButton(groupBox);
        loadGallBtn->setObjectName(QString::fromUtf8("loadGallBtn"));
        loadGallBtn->setGeometry(QRect(130, 10, 100, 32));
        loadGallBtn->setMinimumSize(QSize(100, 32));
        loadGallBtn->setMaximumSize(QSize(100, 32));
        loadVesselBtn = new QPushButton(groupBox);
        loadVesselBtn->setObjectName(QString::fromUtf8("loadVesselBtn"));
        loadVesselBtn->setGeometry(QRect(240, 10, 100, 32));
        loadVesselBtn->setMinimumSize(QSize(100, 32));
        loadVesselBtn->setMaximumSize(QSize(100, 32));

        verticalLayout->addWidget(groupBox);

        ivtkWidget = new QVTKWidget(VolumeViewer);
        ivtkWidget->setObjectName(QString::fromUtf8("ivtkWidget"));

        verticalLayout->addWidget(ivtkWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(VolumeViewer);

        QMetaObject::connectSlotsByName(VolumeViewer);
    } // setupUi

    void retranslateUi(QWidget *VolumeViewer)
    {
        VolumeViewer->setWindowTitle(QApplication::translate("VolumeViewer", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        loadLiverBtn->setText(QApplication::translate("VolumeViewer", "\350\275\275\345\205\245\350\202\235\350\204\217", 0, QApplication::UnicodeUTF8));
        loadGallBtn->setText(QApplication::translate("VolumeViewer", "\350\275\275\345\205\245\350\203\206\345\233\212", 0, QApplication::UnicodeUTF8));
        loadVesselBtn->setText(QApplication::translate("VolumeViewer", "\350\275\275\345\205\245\350\241\200\347\256\241", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VolumeViewer: public Ui_VolumeViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUME_VIEWER_H
