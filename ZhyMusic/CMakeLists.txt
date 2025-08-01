cmake_minimum_required(VERSION 3.16)

project(ZhyMusic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

find_package(Qt6 REQUIRED COMPONENTS Multimedia)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup(REQUIRES 6.5)

qt_add_resources(QML_RESOURCES qrc.qrc res.qrc)

qt_add_executable(${PROJECT_NAME}
    main.cpp
    ${QML_RESOURCES}
    getalbuming.h getalbuming.cpp
    readdata.h readdata.cpp
)


target_link_libraries(ZhyMusic PRIVATE Qt6::Core)
target_link_libraries(ZhyMusic PRIVATE Qt6::Core)
target_link_libraries(ZhyMusic PRIVATE Qt6::Core)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(${PROJECT_NAME} PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appZhyMusic
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
    Qt6::Core
    Qt6::Qml
    Qt6::Multimedia
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
