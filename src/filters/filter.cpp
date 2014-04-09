#include "filter.h"

using namespace MedicalViewer;

void Filter::initParams() {
    initParamsDefinitions();

    std::vector<std::pair<std::string, Filter::ParamType> > def = GetParamDefinitions();
    for(std::vector<std::pair<std::string, Filter::ParamType> >::const_iterator v = def.begin(); v != def.end(); ++v)
        if (v->second == Integer)
            SetIntegerParam(v->first, GetIntegerDefaultValue(v->first));
        else if (v->second == Float)
            SetFloatParam(v->first, GetFloatDefaultValue(v->first));
        else
            SetBooleanParam(v->first, GetBooleanDefaultValue(v->first));
}

std::vector<std::pair<std::string, Filter::ParamType> > Filter::GetParamDefinitions() const {
    return paramDef;
}

std::vector<std::pair<std::string, std::string> > Filter::GetParamDescriptions() const {
    return paramDesc;
}

int Filter::GetIntegerDefaultValue(const std::string &name) const {
    std::map<std::string, int>::const_iterator v = intDefaultParams.find(name);
    if (v == intDefaultParams.end())
        return -1;
    else
        return v->second;
}

int Filter::GetIntegerParam(const std::string &name) const {
    std::map<std::string, int>::const_iterator v = intParams.find(name);
    if (v == intParams.end())
        return -1;
    else
        return v->second;
}


bool Filter::GetBooleanDefaultValue(const std::string &name) const {
    std::map<std::string, bool>::const_iterator v = boolDefaultParams.find(name);
    if (v == boolDefaultParams.end())
        return false;
    else
        return v->second;
}

bool Filter::GetBooleanParam(const std::string &name) const {
    std::map<std::string, bool>::const_iterator v = boolParams.find(name);
    if (v == boolParams.end())
        return false;
    else
        return v->second;
}

float Filter::GetFloatParam(const std::string &name) const {
    std::map<std::string, float>::const_iterator v = floatParams.find(name);
    if (v == floatParams.end())
        return -1.;
    else
        return v->second;
}

float Filter::GetFloatDefaultValue(const std::string &name) const {
    std::map<std::string, float>::const_iterator v = floatDefaultParams.find(name);
    if (v == floatDefaultParams.end())
        return -1.;
    else
        return v->second;
}

void MedicalViewer::Filter::SetIntegerParam(const std::string &name, int value) {
    intParams[name] = value;
}


void MedicalViewer::Filter::SetBooleanParam(const std::string &name, bool value) {
    boolParams[name] = value;
}

void MedicalViewer::Filter::SetFloatParam(const std::string &name, float value) {
    floatParams[name] = value;
}

void MedicalViewer::Filter::SetImage(const itk::Image<float, 3>::Pointer &img) {
    image = img;
}

