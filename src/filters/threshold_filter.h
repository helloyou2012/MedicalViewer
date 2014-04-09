#ifndef BASIC_FILTER_H
#define BASIC_FILTER_H

#include "filter.h"

namespace MedicalViewer {

/**
 * @brief The ThresholdFilter class describe a filter that threshold an image using min and max values
 */
class ThresholdFilter : public Filter {
protected:
    virtual void initParamsDefinitions();
public:

    /**
     * @brief ThresholdFilter Default constructor
     */
    ThresholdFilter();

    /**
     * @brief GetName
     * @return the name of this filter
     */
    std::string GetName() const;
    /**
     * @brief GetDescription
     * @return the description of this filter
     */
    std::string GetDescription() const;

    /**
     * @brief GetOutput
     * @return the output of this filter applied to an input image
     */
    virtual itk::Image<float, 3>::Pointer GetOutput() const;

};

}

#endif // BASIC_FILTER_H
