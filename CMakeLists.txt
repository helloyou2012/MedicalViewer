PROJECT(MedicalViewer)

cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

# Use the include path and library for Qt that is used by VTK.
INCLUDE_DIRECTORIES(${QT_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTXML_INCLUDE_DIR})


INCLUDE_DIRECTORIES(src/contrib/itk-aux/vtk)

# check for ITK
FIND_PACKAGE(ITK)
IF(ITK_FOUND)
  INCLUDE(${ITK_USE_FILE})
ELSE(ITK_FOUND)
  MESSAGE(FATAL_ERROR "ITK not found. Please set ITK_DIR.")
ENDIF(ITK_FOUND)

# check for VTK
FIND_PACKAGE(VTK)
IF(VTK_FOUND)
  INCLUDE(${VTK_USE_FILE})
ELSE(VTK_FOUND)
  MESSAGE(FATAL_ERROR "VTK not found. Please set VTK_DIR.")
ENDIF(VTK_FOUND)



# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif(DOXYGEN_FOUND)



# recursive call
ADD_SUBDIRECTORY(src)
