#ifndef FILTER_H
#define FILTER_H

#include <list>
#include <map>
#include <string>
#include <itkImage.h>

namespace MedicalViewer {

/**
 * @brief The Filter class describe the filter interface that manipulates images
 */
class Filter {
public:
    /**
      Possible types of the filter parameters
    */
    typedef enum {Integer, Float, Boolean} ParamType;
protected:
    /**
     * @brief integer parameters
     */
    std::map<std::string, int> intParams;
    /**
     * @brief float parameters
     */
    std::map<std::string, float> floatParams;
    /**
     * @brief boolean parameters
     */
    std::map<std::string, bool> boolParams;
    /**
     * @brief the input image
     */
    itk::Image<float, 3>::Pointer image;

    /**
     * @brief Type of the parameters
     */
    std::vector<std::pair<std::string, ParamType> > paramDef;
    /**
     * @brief Description of the parameters
     */
    std::vector<std::pair<std::string, std::string> > paramDesc;
    /**
     * @brief default values of the integer parameters
     */
    std::map<std::string, int> intDefaultParams;
    /**
     * @brief default values of the float parameters
     */
    std::map<std::string, float> floatDefaultParams;
    /**
     * @brief default values of the boolean parameters
     */
    std::map<std::string, bool> boolDefaultParams;

protected:
    /**
     * @brief Init the parameters using the default values
     */
    void initParams();
    /**
     * @brief initParamsDefinitions initialize the default values, type and descriptions of the parameters
     */
    virtual void initParamsDefinitions() = 0;
public:

    /**
     * @brief GetParamDefinitions
     * @return a list of all the parameter types
     */
    std::vector<std::pair<std::string, ParamType> > GetParamDefinitions() const;
    /**
     * @brief GetParamDescriptions
     * @return a list of all the parameter descriptions
     */
    std::vector<std::pair<std::string, std::string> > GetParamDescriptions() const;

    /**
     * @brief GetName is an accessor
     * @return the name of the current filter
     */
    virtual std::string GetName() const = 0;
    /**
     * @brief GetDescription is an accessor
     * @return a description of the current filter
     */
    virtual std::string GetDescription() const = 0;

    /**
     * @brief GetIntegerDefaultValue is an accessor for default values
     * @param name Name of the wanted parameter
     * @return the default value of this parameter
     */
    int GetIntegerDefaultValue(const std::string & name) const;
    /**
     * @brief GetFloatDefaultValue is an accessor for default values
     * @param name Name of the wanted parameter
     * @return the default value of this parameter
     */
    float GetFloatDefaultValue(const std::string & name) const;
    /**
     * @brief GetBooleanDefaultValue is an accessor for default values
     * @param name Name of the wanted parameter
     * @return the default value of this parameter
     */
    bool GetBooleanDefaultValue(const std::string & name) const;

    /**
     * @brief GetIntegerParam is an accessor
     * @param name Name of the wanted parameter
     * @return the current value of this parameter
     */
    int GetIntegerParam(const std::string & name) const;
    /**
     * @brief GetFloatParam is an accessor
     * @param name Name of the wanted parameter
     * @return the current value of this parameter
     */
    float GetFloatParam(const std::string & name) const;
    /**
     * @brief GetBooleanParam is an accessor
     * @param name Name of the wanted parameter
     * @return the current value of this parameter
     */
    bool GetBooleanParam(const std::string & name) const;

    /**
     * @brief SetIntegerParam is a modifier
     * @param name Name of the wanted parameter
     * @param value the new value of this parameter
     */
    void SetIntegerParam(const std::string & name, int value);
    /**
     * @brief SetFloatParam is a modifier
     * @param name Name of the wanted parameter
     * @param value the new value of this parameter
     */
    void SetFloatParam(const std::string & name, float value);
    /**
     * @brief SetBooleanParam is a modifier
     * @param name Name of the wanted parameter
     * @param value the new value of this parameter
     */
    void SetBooleanParam(const std::string & name, bool value);

    /**
     * @brief SetImage give an image as input to this filter
     * @param img Input image
     */
    void SetImage(const itk::Image<float, 3>::Pointer & img);

    /**
     * @brief GetOutput apply the filter to the given image
     * @return The result of the filter processing
     */
    virtual itk::Image<float, 3>::Pointer GetOutput() const = 0;

};

}
#endif // FILTER_H
