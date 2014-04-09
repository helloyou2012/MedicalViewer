#include "TMImage.h"

#include <itkImageFileReader.h>
#include <itkImageSeriesReader.h>
#include <itkGDCMImageIO.h>
#include <itkBMPImageIO.h>
#include <itkJPEGImageIO.h>
#include <itkStatisticsImageFilter.h>

using namespace MedicalViewer;

itk::Image<float, 3>::Pointer TMImage::getImage() const {
    return image;
}

itk::Image<float, 3>::Pointer TMImage::getModifiedImage() const
{
    return modifiedImage;
}

void TMImage::setModifiedImage(const itk::Image<float, 3>::Pointer &value)
{
    modified = true;
    modifiedImage = value;
}


bool TMImage::getModified() const
{
    return modified;
}

unsigned int TMImage::getNbSlices() const
{
    if (modifiedImage.IsNull())
        return 0;
    else
        return modifiedImage->GetLargestPossibleRegion().GetSize()[2];
}

void TMImage::loadSerie(const std::vector<std::string> &names, const std::string &suffix) {
    const bool w = itk::Object::GetGlobalWarningDisplay();
    itk::Object::SetGlobalWarningDisplay(false);

    typedef itk::ImageSeriesReader<itk::Image<float, 3> > ReaderType;
    ReaderType::Pointer reader = ReaderType::New();

    if(suffix=="bmp"){
        reader->SetImageIO(itk::BMPImageIO::New());
    }else if(suffix=="jpg"||suffix=="jpeg"){
        reader->SetImageIO(itk::JPEGImageIO::New());
    }else{
        reader->SetImageIO(itk::GDCMImageIO::New());
    }

    reader->SetFileNames(names);

    try {
        reader->Update();
        image = reader->GetOutput();
        modifiedImage = image;
        modified = false;
    }catch (itk::ExceptionObject &ex) {
        itk::Object::SetGlobalWarningDisplay(w);
        throw itk::ExceptionObject(ex);
    }
}

TMImage::TMImage() : modified(false) {

}

bool TMImage::loadImage(const std::vector<std::string> &names, const std::string &suffix) {
    try {
        loadSerie(names, suffix);
        std::cout<<"load series ....."<<std::endl;
        return true;
    }catch (itk::ExceptionObject & eo) {}
    return false;
}

bool TMImage::isLoaded() const {
    return image.IsNotNull();
}


