
FIND_PACKAGE(Qt4 REQUIRED QtCore QtGui QtXml)
INCLUDE(${QT_USE_FILE})

# set the target libraries
SET(TARGET_LIBS QVTK ${QT_LIBRARIES} ITKCommon vtkRendering vtkGraphics vtkIO vtkCommon vtkInfovis vtkViews)


# include the current binary dir for the generated header files (UI)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

SET(MainSrcs main.cpp main_window.cpp)
SET(MainUI main_window.ui)
SET(MainHeaders main_window.h global.h)
SET(MainResources resources.qrc)

QT4_WRAP_UI(TV_UISrcs ${MainUI})
QT4_WRAP_CPP(TV_MOCSrcs ${MainHeaders})
QT4_ADD_RESOURCES(TV_ResourceSrcs ${MainResources})

SOURCE_GROUP("Resources" FILES
  ${MainUI}
  ${MainResources}
)

SOURCE_GROUP("Generated" FILES
  ${TV_UISrcs}
  ${TV_MOCSrcs}
  ${TV_ResourceSrcs}
  ${TV_RCS_SOURCES}
)

#ADD_DEFINITIONS(-DQT_GUI_LIBS -DQT_CORE_LIB -DQT_XML_LIB -DQT3_SUPPORT)
#SET_SOURCE_FILES_PROPERTIES(${MainSrcs} PROPERTIES
#                            OBJECT_DEPENDS "${TV_UISrcs}")

ADD_EXECUTABLE(medical_viewer ${MainSrcs} ${TV_UISrcs} ${TV_MOCSrcs} ${TV_ResourceSrcs})

TARGET_LINK_LIBRARIES(medical_viewer Viewer Qxt Filters Core ${TARGET_LIBS} ${ITK_LIBRARIES} ${VTK_LIBRARIES})

#SET_TARGET_PROPERTIES(medical_viewer PROPERTIES COMPILE_FLAGS "${SHARED_FLAGS} ${TECHMED_flags}")
