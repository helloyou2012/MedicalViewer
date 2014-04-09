/********************************************************************************
** Form generated from reading UI file 'plane_viewer.ui'
**
** Created: Mon Jan 6 20:01:57 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANE_VIEWER_H
#define UI_PLANE_VIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PlaneViewer
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QPushButton *openButton;
    QCheckBox *resliceModeCheckBox;
    QCheckBox *thickModeCheckBox;
    QPushButton *addDistance1Button;
    QPushButton *resetButton;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QVTKWidget *view2;
    QVTKWidget *view4;
    QVTKWidget *view3;
    QVTKWidget *view1;
    QGroupBox *blendModeGroupBox;
    QRadioButton *radioButton_Min;
    QRadioButton *radioButton_Max;
    QRadioButton *radioButton_Mean;

    void setupUi(QWidget *PlaneViewer)
    {
        if (PlaneViewer->objectName().isEmpty())
            PlaneViewer->setObjectName(QString::fromUtf8("PlaneViewer"));
        PlaneViewer->resize(680, 490);
        verticalLayout_2 = new QVBoxLayout(PlaneViewer);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(PlaneViewer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        groupBox->setMaximumSize(QSize(16777215, 50));
        openButton = new QPushButton(groupBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(10, 10, 98, 31));
        openButton->setMaximumSize(QSize(100, 32));
        resliceModeCheckBox = new QCheckBox(groupBox);
        resliceModeCheckBox->setObjectName(QString::fromUtf8("resliceModeCheckBox"));
        resliceModeCheckBox->setGeometry(QRect(320, 16, 161, 21));
        thickModeCheckBox = new QCheckBox(groupBox);
        thickModeCheckBox->setObjectName(QString::fromUtf8("thickModeCheckBox"));
        thickModeCheckBox->setGeometry(QRect(490, 20, 161, 17));
        addDistance1Button = new QPushButton(groupBox);
        addDistance1Button->setObjectName(QString::fromUtf8("addDistance1Button"));
        addDistance1Button->setGeometry(QRect(110, 10, 100, 31));
        addDistance1Button->setMaximumSize(QSize(100, 32));
        resetButton = new QPushButton(groupBox);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(220, 10, 71, 31));

        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        view2 = new QVTKWidget(PlaneViewer);
        view2->setObjectName(QString::fromUtf8("view2"));

        gridLayout->addWidget(view2, 1, 0, 1, 1);

        view4 = new QVTKWidget(PlaneViewer);
        view4->setObjectName(QString::fromUtf8("view4"));

        gridLayout->addWidget(view4, 0, 1, 1, 1);

        view3 = new QVTKWidget(PlaneViewer);
        view3->setObjectName(QString::fromUtf8("view3"));

        gridLayout->addWidget(view3, 1, 1, 1, 1);

        view1 = new QVTKWidget(PlaneViewer);
        view1->setObjectName(QString::fromUtf8("view1"));

        gridLayout->addWidget(view1, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        blendModeGroupBox = new QGroupBox(PlaneViewer);
        blendModeGroupBox->setObjectName(QString::fromUtf8("blendModeGroupBox"));
        blendModeGroupBox->setMinimumSize(QSize(200, 0));
        blendModeGroupBox->setMaximumSize(QSize(200, 16777215));
        radioButton_Min = new QRadioButton(blendModeGroupBox);
        radioButton_Min->setObjectName(QString::fromUtf8("radioButton_Min"));
        radioButton_Min->setGeometry(QRect(20, 30, 171, 17));
        radioButton_Max = new QRadioButton(blendModeGroupBox);
        radioButton_Max->setObjectName(QString::fromUtf8("radioButton_Max"));
        radioButton_Max->setGeometry(QRect(20, 50, 181, 17));
        radioButton_Mean = new QRadioButton(blendModeGroupBox);
        radioButton_Mean->setObjectName(QString::fromUtf8("radioButton_Mean"));
        radioButton_Mean->setGeometry(QRect(20, 70, 171, 17));

        horizontalLayout->addWidget(blendModeGroupBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PlaneViewer);

        QMetaObject::connectSlotsByName(PlaneViewer);
    } // setupUi

    void retranslateUi(QWidget *PlaneViewer)
    {
        PlaneViewer->setWindowTitle(QApplication::translate("PlaneViewer", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        openButton->setText(QApplication::translate("PlaneViewer", "\350\275\275\345\205\245\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        resliceModeCheckBox->setText(QApplication::translate("PlaneViewer", "Oblique Reslice", 0, QApplication::UnicodeUTF8));
        thickModeCheckBox->setText(QApplication::translate("PlaneViewer", "Thick Slab", 0, QApplication::UnicodeUTF8));
        addDistance1Button->setText(QApplication::translate("PlaneViewer", "\346\265\213\351\207\217\350\267\235\347\246\273", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("PlaneViewer", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        blendModeGroupBox->setTitle(QApplication::translate("PlaneViewer", "Blend mode", 0, QApplication::UnicodeUTF8));
        radioButton_Min->setText(QApplication::translate("PlaneViewer", "Min Intensity Blend", 0, QApplication::UnicodeUTF8));
        radioButton_Max->setText(QApplication::translate("PlaneViewer", "Max Intensity Blend", 0, QApplication::UnicodeUTF8));
        radioButton_Mean->setText(QApplication::translate("PlaneViewer", "Mean Blend", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PlaneViewer: public Ui_PlaneViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANE_VIEWER_H
