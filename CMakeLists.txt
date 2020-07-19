cmake_minimum_required(VERSION 3.1.0)

project(OSGHud)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)
FIND_PACKAGE( OpenSceneGraph COMPONENTS osgDB osgGA osgViewer osg osgUtil osgText)

include_directories(${OCE_INCLUDE_DIRS})

add_executable(osghud
    mainwindow.ui
    qtosgwidget.cpp
    osghud.cpp
    mainwindow.cpp
    main.cpp
)

target_link_libraries(osghud Qt5::Widgets ${OPENSCENEGRAPH_LIBRARIES} FWOSPlugin)
