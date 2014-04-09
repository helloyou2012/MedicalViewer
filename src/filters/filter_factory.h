#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include "filter.h"
#include <vector>

namespace MedicalViewer {


/**
 * @brief The FilterFactory class generate the list of all the available filters
 * It's a singleton
 */
class FilterFactory
{
private:

    std::vector<Filter *> existing_filters;
    FilterFactory();

    ~FilterFactory();

public:
    /**
     * @brief GetInstance return
     * @return the singleton corresponding to the current class
     */
    static FilterFactory & GetInstance() {
        static FilterFactory instance;
        return instance;
    }
    /**
     * @brief getFilters
     * @return a list of all the existing filters
     */
    const std::vector<Filter *> & getFilters() const;
};

}

#endif // FILTER_FACTORY_H
