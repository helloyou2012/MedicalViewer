#ifndef FILTER_DIALOG_H
#define FILTER_DIALOG_H

#include <QDialog>
#include <QAbstractSpinBox>
#include "../filters/filter.h"

namespace Ui {
class FilterDialog;
}
class QSignalMapper;

namespace MedicalViewer {

/**
 * @brief The FilterDialog class is a dialog to set a filter
 */
class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param f manipulated filter
     * @param parent parent class
     */
    explicit FilterDialog(Filter &f, QWidget *parent = 0);
    /**
     * @brief Destructor
     */
    ~FilterDialog();

    /**
     * @brief The filter has to be applied on the original image?
     * @return true if the input image is the original
     */
    bool applyOnOriginal() const;

private:
    Ui::FilterDialog *ui;
    std::vector<std::string> paramNames;
    std::vector<QWidget *> forms;

    Filter & filter;
    QSignalMapper * pMapper;
public Q_SLOTS:
    /**
     * @brief A parameter value has been modified
     * @param p ID of the parameter
     */
    virtual void slotModifiedParam(int p);
    /**
     * @brief Reset the values to the default
     */
    virtual void slotResetDefaults();
};
}

#endif // FILTER_DIALOG_H
