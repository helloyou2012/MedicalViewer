#include "filter_dialog.h"
#include "ui_filter_dialog.h"
#include "../filters/filter.h"

#include <QSignalMapper>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

using namespace MedicalViewer;

FilterDialog::FilterDialog(Filter &f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog()), filter(f) {
    ui->setupUi(this);
    ui->description->setText(filter.GetDescription().c_str());
    // adjust the size of the text box
    QFontMetrics m(ui->description->font());
    ui->description->setFixedHeight(4 * m.lineSpacing());

    pMapper = new QSignalMapper(this);
    std::vector<std::pair<std::string, Filter::ParamType> > definitions = filter.GetParamDefinitions();
    std::vector<std::pair<std::string, std::string> > descriptions = filter.GetParamDescriptions();
    assert(definitions.size() == descriptions.size());
    std::vector<std::pair<std::string, std::string> >::const_iterator desc = descriptions.begin();
    unsigned int i = 0;
    for(std::vector<std::pair<std::string, Filter::ParamType> >::const_iterator def = definitions.begin();
        def != definitions.end(); ++def, ++desc)
        if (def->first == desc->first) {
            paramNames.push_back(def->first);
            QFormLayout * layout = qobject_cast<QFormLayout *>(ui->parameters->layout());
            QWidget * paramEditor;
            if (def->second == Filter::Integer) {
                QSpinBox * pe = new QSpinBox(ui->parameters);
                pe->setValue(filter.GetIntegerParam(def->first));
                pe->setMinimum(-std::numeric_limits<int>::max());
                pe->setMaximum(std::numeric_limits<int>::max());
                paramEditor = pe;
                connect(pe, SIGNAL(valueChanged(QString)), pMapper, SLOT(map()));
            }
            else if (def->second == Filter::Float) {
                QDoubleSpinBox * pe = new QDoubleSpinBox(ui->parameters);
                pe->setValue(filter.GetFloatParam(def->first));
                pe->setMinimum(-std::numeric_limits<float>::max());
                pe->setMaximum(std::numeric_limits<float>::max());
                paramEditor = pe;
                connect(pe, SIGNAL(valueChanged(QString)), pMapper, SLOT(map()));
            }
            else {
                QCheckBox * re = new QCheckBox(ui->parameters);
                re->setChecked(filter.GetBooleanParam(def->first));
                re->setText("");
                paramEditor = re;
                connect(re, SIGNAL(stateChanged(int)), pMapper, SLOT(map()));
            }
            forms.push_back(paramEditor);
            pMapper->setMapping(paramEditor, i);
            layout->addRow(desc->second.c_str(), paramEditor);

            ++i;
        }
    connect(pMapper, SIGNAL(mapped(int)), this, SLOT(slotModifiedParam(int)));

    QPushButton* resetButton = ui->buttonBox->button(QDialogButtonBox::RestoreDefaults);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(slotResetDefaults()));
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

bool FilterDialog::applyOnOriginal() const {
    return ui->onOriginal->isChecked();
}

void FilterDialog::slotModifiedParam(int p) {
    std::string key = paramNames[p];
    QWidget * sbox = forms[p];
    QSpinBox * intsb = qobject_cast<QSpinBox *>(sbox);
    if (intsb == NULL) {
        QDoubleSpinBox * floatsb = qobject_cast<QDoubleSpinBox *>(sbox);
        if (floatsb == NULL) {
            QCheckBox * boolrb = qobject_cast<QCheckBox *>(sbox);
            filter.SetBooleanParam(key, boolrb->isChecked());
        }
        else
            filter.SetFloatParam(key, floatsb->value());
    }
    else {
        filter.SetIntegerParam(key, intsb->value());
    }
}

void FilterDialog::slotResetDefaults() {
    std::vector<std::string>::const_iterator name = paramNames.begin();
    for(std::vector<QWidget *>::const_iterator sbox = forms.begin();
        sbox != forms.end(); ++sbox, ++name) {
        QSpinBox * intsb = qobject_cast<QSpinBox *>(*sbox);
        if (intsb == NULL) {
            QDoubleSpinBox * floatsb = qobject_cast<QDoubleSpinBox *>(*sbox);
            if (floatsb == NULL) {
                QCheckBox * boolrb = qobject_cast<QCheckBox *>(*sbox);
                boolrb->setChecked(filter.GetBooleanParam(*name));
            }
            else
                floatsb->setValue(filter.GetFloatDefaultValue(*name));
        }
        else {
            intsb->setValue(filter.GetIntegerDefaultValue(*name));
        }
    }
}
