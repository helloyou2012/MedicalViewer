FIND_PACKAGE(Qt4 REQUIRED QtCore QtGui QtXml)
INCLUDE(${QT_USE_FILE})

IF(NOT VTK_BINARY_DIR)
FIND_PACKAGE(VTK)
IF(NOT VTK_DIR)
  MESSAGE(FATAL_ERROR "Please set VTK_DIR.")
ENDIF(NOT VTK_DIR)
INCLUDE(${VTK_USE_FILE})
ENDIF(NOT VTK_BINARY_DIR)

# set the target libraries
SET(TARGET_LIBS QVTK ${QT_LIBRARIES} ITKCommon vtkRendering vtkGraphics vtkIO vtkCommon vtkInfovis vtkViews)


# include the current binary dir for the generated header files (UI)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

SET(ViewerSrcs filter_dialog.cpp slice_viewer.cpp plane_viewer.cpp volume_viewer.cpp)
SET(ViewerUI filter_dialog.ui plane_viewer.ui volume_viewer.ui)
SET(ViewerHeaders filter_dialog.h slice_viewer.h plane_viewer.h volume_viewer.h)

QT4_WRAP_UI(TV_UISrcs ${ViewerUI})
QT4_WRAP_CPP(TV_MOCSrcs ${ViewerHeaders})
QT4_ADD_RESOURCES(TV_ResourceSrcs ${ViewerResources})

SOURCE_GROUP("Resources" FILES
  ${ViewerUI}
  ${ViewerResources}
  ${EXE_ICON}
)

SOURCE_GROUP("Generated" FILES
  ${TV_UISrcs}
  ${TV_MOCSrcs}
  ${TV_ResourceSrcs}
  ${TV_RCS_SOURCES}
)

add_library(Viewer ${ViewerSrcs} ${TV_UISrcs} ${TV_MOCSrcs} ${TV_ResourceSrcs})
