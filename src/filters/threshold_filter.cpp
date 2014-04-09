#include "threshold_filter.h"

#include <itkThresholdImageFilter.h>
#include <itkMinimumMaximumImageCalculator.h>

using namespace MedicalViewer;



ThresholdFilter::ThresholdFilter() : Filter() {
    initParams();
}

void ThresholdFilter::initParamsDefinitions() {
    paramDef.clear();
    paramDef.push_back(std::pair<std::string, Filter::ParamType>("set_minimum_value", Boolean));
    paramDef.push_back(std::pair<std::string, Filter::ParamType>("minimum_value", Float));
    paramDef.push_back(std::pair<std::string, Filter::ParamType>("set_maximum_value", Boolean));
    paramDef.push_back(std::pair<std::string, Filter::ParamType>("maximum_value", Float));
    paramDef.push_back(std::pair<std::string, Filter::ParamType>("output_value", Float));

    paramDesc.clear();
    paramDesc.push_back(std::pair<std::string, std::string>("set_minimum_value", "Set minimum value"));
    paramDesc.push_back(std::pair<std::string, std::string>("minimum_value", "Minimum value"));
    paramDesc.push_back(std::pair<std::string, std::string>("set_maximum_value", "Set maximum value"));
    paramDesc.push_back(std::pair<std::string, std::string>("maximum_value", "Maximum value"));
    paramDesc.push_back(std::pair<std::string, std::string>("output_value", "Output value"));

    boolDefaultParams.clear();
    boolDefaultParams["set_minimum_value"] = true;
    boolDefaultParams["set_maximum_value"] = true;

    floatDefaultParams.clear();
    floatDefaultParams["minimum_value"] = 0.;
    floatDefaultParams["maximum_value"] = 100.;
    floatDefaultParams["output_value"] = 0.;
    intDefaultParams.clear();

}



std::string ThresholdFilter::GetName() const {
    return "Basic threshold";
}

std::string ThresholdFilter::GetDescription() const {
    return "Preserve only valyes inbetween the minimum and maximum given values. The other pixels are modified using the output value.";
}

itk::Image<float, 3>::Pointer ThresholdFilter::GetOutput() const {
    typedef itk::ThresholdImageFilter<itk::Image<float, 3> > ThresholdImageFilterType;

    ThresholdImageFilterType::Pointer thresholdFilter = ThresholdImageFilterType::New();
    thresholdFilter->SetInput(image);

    itk::MinimumMaximumImageCalculator<itk::Image<float, 3> >::Pointer calculator;
    calculator = itk::MinimumMaximumImageCalculator<itk::Image<float, 3> >::New();
    calculator->SetImage(image);
    calculator->Compute();
    float minColor, maxColor;
    if (GetBooleanParam("set_minimum_value"))
        minColor = GetFloatParam("minimum_value");
    else
        minColor = calculator->GetMinimum();
    if (GetBooleanParam("set_maximum_value"))
        maxColor = GetFloatParam("maximum_value");
    else
        maxColor = calculator->GetMaximum();

    if (minColor < calculator->GetMinimum())
        minColor = calculator->GetMinimum();
    if (minColor > calculator->GetMaximum())
        minColor = calculator->GetMaximum();

    if (maxColor < calculator->GetMinimum())
        maxColor = calculator->GetMinimum();
    if (maxColor > calculator->GetMaximum())
        maxColor = calculator->GetMaximum();
    assert(minColor <= maxColor);

    thresholdFilter->ThresholdOutside(minColor, maxColor);
    thresholdFilter->SetOutsideValue(GetFloatParam("output_value"));
    thresholdFilter->Update();
    return thresholdFilter->GetOutput();
}
