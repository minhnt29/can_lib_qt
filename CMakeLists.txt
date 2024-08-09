cmake_minimum_required(VERSION 3.28)
project(can_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wa,-mbig-obj")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s -Wall -Wextra")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        SerialBus
        REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_parties/spdlog/include)

file(GLOB_RECURSE HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
                         ${CMAKE_CURRENT_SOURCE_DIR}/can_lib/*.h
                         ${CMAKE_CURRENT_SOURCE_DIR}/dbc_handle/*.h
                         ${CMAKE_CURRENT_SOURCE_DIR}/logger/*.h)

file(GLOB_RECURSE CPP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
                              ${CMAKE_CURRENT_SOURCE_DIR}/can_lib/*.cpp
                              ${CMAKE_CURRENT_SOURCE_DIR}/dbc_handle/*.cpp
                              ${CMAKE_CURRENT_SOURCE_DIR}/logger/*.cpp)

add_executable(${PROJECT_NAME} ${HEADER} ${CPP_SOURCES})
target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::SerialBus
)
#
#if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#    set(DEBUG_SUFFIX)
#    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d")
#    endif ()
#    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
#    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        endif ()
#    endif ()
#    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E make_directory
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#    endif ()
#    foreach (QT_LIB Core Gui Widgets)
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
#    endforeach (QT_LIB)
#endif ()
