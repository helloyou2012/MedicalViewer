#include "filter_factory.h"

#include "threshold_filter.h"

using namespace MedicalViewer;

FilterFactory::FilterFactory() {
    existing_filters.push_back(new ThresholdFilter());
}

FilterFactory::~FilterFactory() {
    for(std::vector<Filter *>::const_iterator f = existing_filters.begin();
        f != existing_filters.end(); ++f)
        delete *f;
}

const std::vector<Filter *> &FilterFactory::getFilters() const {
    return existing_filters;
}

