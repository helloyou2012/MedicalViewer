/********************************************************************************
** Form generated from reading UI file 'filter_dialog.ui'
**
** Created: Mon Jan 6 20:01:57 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_DIALOG_H
#define UI_FILTER_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QGridLayout *gridLayout;
    QScrollArea *parametersArea;
    QWidget *parameters;
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QTextEdit *description;
    QCheckBox *onOriginal;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName(QString::fromUtf8("FilterDialog"));
        FilterDialog->resize(404, 294);
        gridLayout = new QGridLayout(FilterDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        parametersArea = new QScrollArea(FilterDialog);
        parametersArea->setObjectName(QString::fromUtf8("parametersArea"));
        parametersArea->setMinimumSize(QSize(384, 0));
        parametersArea->setWidgetResizable(true);
        parameters = new QWidget();
        parameters->setObjectName(QString::fromUtf8("parameters"));
        parameters->setGeometry(QRect(0, 0, 386, 68));
        formLayout = new QFormLayout(parameters);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        parametersArea->setWidget(parameters);

        gridLayout->addWidget(parametersArea, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(FilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);

        scrollArea = new QScrollArea(FilterDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 386, 163));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        description = new QTextEdit(scrollAreaWidgetContents);
        description->setObjectName(QString::fromUtf8("description"));
        description->setEnabled(true);
        description->setReadOnly(true);

        verticalLayout->addWidget(description);

        onOriginal = new QCheckBox(scrollAreaWidgetContents);
        onOriginal->setObjectName(QString::fromUtf8("onOriginal"));

        verticalLayout->addWidget(onOriginal);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 2);


        retranslateUi(FilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QApplication::translate("FilterDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        onOriginal->setText(QApplication::translate("FilterDialog", "Apply on original", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_DIALOG_H
