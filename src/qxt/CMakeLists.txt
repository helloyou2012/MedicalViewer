# Find QT 
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE( ${QT_USE_FILE} )

# support for out-of-source build
INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_BINARY_DIR} #this is where ui_Qxt.h is generated
  ${CMAKE_CURRENT_SOURCE_DIR}
)
 
 
 
# Set your files and resources here
SET(QxtSrcs qxtglobal.cpp qxtspanslider.cpp)
SET(QxtHeaders qxtglobal.h qxtspanslider.h qxtspanslider_p.h)
 
# for generate qt aditional files 
QT4_WRAP_CPP(MOCSrcs ${QxtHeaders} )
 
SOURCE_GROUP("Generated" FILES
  ${MOCSrcs}
)
add_library(Qxt ${QxtSrcs} ${QxtHeaders} ${MOCSrcs})
