cmake_minimum_required(VERSION 3.20)
project(cpp_qml_module)
find_package(Qt6 COMPONENTS Core Quick QuickControls2 REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME}
    main.cpp
    qrc.qrc
    mypainter.h mypainter.cpp
)

#添加c++扩展qml库
qt_add_qml_module(
    ${PROJECT_NAME}
    URI Cpp.MyPainter
)

# 指定qml加载库的路径
set(QML_IMPORT_PATH ${CMAKE_BINARY_DIR})

target_link_libraries(cpp_qml_module PRIVATE Qt6::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick Qt6::QuickControls2)
