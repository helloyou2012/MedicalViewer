#ifndef TMIMAGE_H
#define TMIMAGE_H
#include <string>
#include "itkImage.h"

using namespace std;

namespace MedicalViewer {


/**
 * @brief The TMImage class describe an image in memory
 */
class TMImage {
private:
    /**
     * @brief The loaded image
     */
    itk::Image<float, 3>::Pointer image;
    /**
     * @brief name
     */
    itk::Image<float, 3>::Pointer modifiedImage;
    bool modified;

    void loadSerie(const std::vector<std::string> &names, const std::string &suffix);
public:
    /**
     * @brief default constructor
     */
    TMImage();

    /**
     * @brief Load an image. If the image cannot be loaded, it keeps the original state of object
     * @param fName An image to load
     * @return true if the image has been correctly loaded.
     *
     */
    bool loadImage(const std::vector<std::string> &names, const std::string &suffix);

    /**
     * @brief Check if an image has been loaded
     * @return true if an image is loaded
     */
    bool isLoaded() const;

    /**
     * @brief getImage Get the loaded image
     * @return the loaded image
     */
    itk::Image<float, 3>::Pointer getImage() const;
    /**
     * @brief Get the modified image
     * @return the modified image
     */
    itk::Image<float, 3>::Pointer getModifiedImage() const;
    /**
     * @brief set the modified image
     * @param value the new modified image
     */
    void setModifiedImage(const itk::Image<float, 3>::Pointer &value);
    /**
     * @brief Is the image modified?
     * @return true if the image has been modified
     */
    bool getModified() const;

    /**
     * @brief Get the number of slices of the current image
     * @return Number of slices of the current image
     */
    unsigned int getNbSlices() const;
};
}

#endif // TMIMAGE_H
