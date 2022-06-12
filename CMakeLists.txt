cmake_minimum_required(VERSION 3.10.1)

file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/VERSION" QCLASH_VERSION)
file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/BUILDVERSION" QCLASH_BUILD_VERSION)
file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/VERSIONSUFFIX" QCLASH_VERSION_SUFFIX)

set(QCLASH_VERSION_STRING "${QCLASH_VERSION}${QCLASH_VERSION_SUFFIX}")
project(Qvmessocket)

set(VERSION_LIST ${QCLASH_VERSION})
string(REPLACE "." ";" VERSION_LIST ${VERSION_LIST})
separate_arguments(VERSION_LIST)

list(GET VERSION_LIST 0 CMAKE_PROJECT_VERSION_MAJOR)
list(GET VERSION_LIST 1 CMAKE_PROJECT_VERSION_MINOR)
list(GET VERSION_LIST 2 CPACK_PACKAGE_VERSION_PATCH)

add_definitions(-DQCLASH_VERSION_MAJOR=${CMAKE_PROJECT_VERSION_MAJOR})
add_definitions(-DQCLASH_VERSION_MINOR=${CMAKE_PROJECT_VERSION_MINOR})
add_definitions(-DQCLASH_VERSION_BUGFIX=${CPACK_PACKAGE_VERSION_PATCH})
add_definitions(-DQCLASH_VERSION_BUILD=${QCLASH_BUILD_VERSION})
add_definitions(-DQCLASH_VERSION_STRING="${QCLASH_VERSION_STRING}")

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(WIN32)
    include(cmake/versioninfo/generate_product_version.cmake)
    generate_product_version(
        QVMESSOCKET_RC
        NAME               "Qclash"
        BUNDLE             "clash Project Family"
        ICON               "${CMAKE_SOURCE_DIR}/assets/icons/qclash.ico"
        VERSION_MAJOR      ${CMAKE_PROJECT_VERSION_MAJOR}
        VERSION_MINOR      ${CMAKE_PROJECT_VERSION_MINOR}
        VERSION_PATCH      ${CPACK_PACKAGE_VERSION_PATCH}
        VERSION_REVISION   ${QCLASH_BUILD_VERSION}
        COMPANY_NAME       "Qclash"
        COMPANY_COPYRIGHT  "Qclash"
        FILE_DESCRIPTION   "Qclash Main Application"
        )
    add_definitions(-DUNICODE -D_UNICODE -DNOMINMAX)
    set(GUI_TYPE WIN32)
    add_compile_options("/utf-8")
    add_compile_options("/std:c++17")
    add_definitions(-D_WIN32_WINNT=0x600 -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS)
    set(QCLASH_PLATFORM_LIBS_PREFIX ${CMAKE_SOURCE_DIR}/libs/x64-windows/)
    include(cmake/platforms/prefixes.cmake)
endif()

if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.17.0")
    cmake_policy(SET CMP0100 NEW)
endif()

option(QCLASH_AUTO_DEPLOY "Automatically run deploy command after build" ON)
set(QCLASH_DEFAULT_VASSETS_PATH "unset" CACHE STRING "Default assets path")
set(QCLASH_DEFAULT_VCORE_PATH "unset" CACHE STRING "Default core path")
option(QCLASH_DISABLE_AUTO_UPDATE "Disable Update Checker" OFF)
option(QCLASH_HAS_BUILTIN_PLUGINS "Build with builtin plugins" ON)
option(QCLASH_EMBED_TRANSLATIONS "Embed Translations" OFF)
option(QCLASH_HAS_SINGLEAPPLICATION "Build With SingleApplication" ON)
set(QCLASH_UI_TYPE "QWidget" CACHE STRING "GUI Component")

if(QCLASH_UI_TYPE STREQUAL "QWidget")
    set(QCLASH_USE_QWIDGET ON)
endif()

if(QCLASH_HAS_SINGLEAPPLICATION)
    set(QVMESSOCKET_SINGLEAPPLICATION_PROVIDER "module" CACHE STRING "SingleApplication Provider")
endif()

if(QCLASH_USE_QWIDGET)
    option(QVMESSOCKET_HAS_BUILTIN_THEMES "Build with built-in themes" ON)
    set(QVMESSOCKET_QNODEEDITOR_PROVIDER "module" CACHE STRING "QNodeEditor Provider")
endif()

cmake_policy(SET CMP0072 NEW)
set(QV_QT_MAJOR_VERSION 6)
set(QV_QT_MINOR_VERSION 0)
set(QV_QT_LIBNAME Qt6)

if(QCLASH_DEFAULT_VCORE_PATH AND NOT QCLASH_DEFAULT_VCORE_PATH STREQUAL "unset")
    add_definitions(-DQVMESSOCKET_DEFAULT_VCORE_PATH="${QVMESSOCKET_DEFAULT_VCORE_PATH}")
endif()
if(QCLASH_DEFAULT_VASSETS_PATH AND NOT QCLASH_DEFAULT_VASSETS_PATH STREQUAL "unset")
    add_definitions(-DQMESSOCKET_DEFAULT_VASSETS_PATH="${QCLASH_DEFAULT_VASSETS_PATH}")
endif()

if(QCLASH_DISABLE_AUTO_UPDATE)
    add_definitions(-DDISABLE_AUTO_UPDATE)
endif()

add_definitions(-D_QCLASH_BUILD_INFO_STR_="${_QCLASH_BUILD_INFO_STR_}")
add_definitions(-D_QCLASH_BUILD_EXTRA_INFO_STR_="${_QCLASH_BUILD_EXTRA_INFO_STR_}")

include(cmake/libuv.cmake)
include(cmake/libcurl.cmake)
include(cmake/libsemver.cmake)
include(cmake/protobuf.cmake)
include(cmake/backend.cmake)
include(3rdparty/QJsonStruct/QJsonStruct.cmake)

find_package(Threads REQUIRED)
find_package(${QV_QT_LIBNAME} ${QV_QT_MAJOR_VERSION}.${QV_QT_MINOR_VERSION} COMPONENTS Core Network REQUIRED)
list(APPEND QCLASH_QT_LIBS ${QV_QT_LIBNAME}::Core ${QV_QT_LIBNAME}::Network)

cmake_policy(SET CMP0071 NEW)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(QCLASH_USE_QWIDGET)
    find_package(${QV_QT_LIBNAME} ${QV_QT_MAJOR_VERSION}.${QV_QT_MINOR_VERSION} COMPONENTS Widgets Svg Gui REQUIRED)
    list(APPEND QCLASH_QT_LIBS
        ${QV_QT_LIBNAME}::Widgets
        ${QV_QT_LIBNAME}::Svg
        ${QV_QT_LIBNAME}::Gui)
    set(_QCLASH_HAS_GUI_INTERNAL_ ON)
endif()

include(cmake/components/base.cmake)
include(src/plugin-interface/QvPluginInterface.cmake)

if(QCLASH_HAS_SINGLEAPPLICATION)
    include(cmake/singleapplication.cmake)
else()
    add_definitions(-DQCLASH_NO_SINGLEAPPLICATON)
endif()

add_library(Qvmessocket_baselib STATIC
    ${QVMESSOCKET_BASE_SOURCES}
    ${SINGLEAPPLICATION_SOURCES}
    ${QVPLUGIN_INTERFACE_HEADERS}
    ${LIBSEMVER_SOURCES}
    ${PROTO_SRCS}
    ${PROTO_HDRS}
    ${API_GRPC_SRCS}
    ${API_PROTO_SRCS}
    )

target_link_libraries(Qvmessocket_baselib
    ${QCLASH_QT_LIBS}
    ${QVMESSOCKET_PROTOBUF_LIBRARY}
    ${QVMESSOCKET_BACKEND_LIBRARY}
    ${LibUV_LIBRARIES}
    ${CURL_LIBRARIES}
    ${SINGLEAPPLICATION_LIBRARY}
    Threads::Threads
    )

target_include_directories(Qvmessocket_baselib PUBLIC
    ${CMAKE_BINARY_DIR}
    ${LibUV_INCLUDE_DIR}
    ${SINGLEAPPLICATION_DIR}
    ${CURL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Protobuf_INCLUDE_DIRS}
    )

if(QCLASH_HAS_BUILTIN_PLUGINS)
    include(src/plugins/protocols/QvPlugin-BuiltinProtocolSupport.cmake)
    include(src/plugins/subscription-adapters/QvPlugin-BuiltinSubscriptionAdapters.cmake)
    #include(src/plugins/utils/QvPlugin-BuiltinUtils.cmake)
endif()

if(_QCLASH_HAS_GUI_INTERNAL_)
    add_definitions(-DQVMESSOCKET_GUI)
    include(cmake/qrencode.cmake)
    include(cmake/components/ui.cmake)
    list(APPEND QVMESSOCKET_UI_SOURCES ${QVMESSOCKET_UI_COMMON_SOURCES})
    include(src/plugin-interface/QvGUIPluginInterface.cmake)
    list(APPEND QVMESSOCKET_UI_SOURCES ${QVGUIPLUGIN_INTERFACE_HEADERS})
    if(QCLASH_USE_QWIDGET)
        add_definitions(-DQVMESSOCKET_GUI_QWIDGETS)
        include(cmake/components/ui-widget.cmake)
        list(APPEND QVMESSOCKET_UI_SOURCES ${QVMESSOCKET_UI_WIDGET_SOURCES})
        if (QVMESSOCKET_HAS_BUILTIN_THEMES)
            include(3rdparty/uistyles/uistyles.cmake)
            list(APPEND QVMESSOCKET_QRC_RESOURCES ${UISTYLE_QRCS})
        endif()
        include(cmake/qnodeeditor.cmake)
        list(APPEND QVMESSOCKET_QRC_RESOURCES ${QNODEEDITOR_QRC_RESOURCES})
    endif()
endif()

list(APPEND QVMESSOCKET_QRC_RESOURCES
    ${CMAKE_SOURCE_DIR}/resources.qrc
    ${CMAKE_SOURCE_DIR}/resources.new.qrc
    )

set(QVMESSOCKET_FULL_SOURCES
    ${QVMESSOCKET_RC}
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    ${QVMESSOCKET_UI_SOURCES}
    ${QCLASH_EMBED_TRANSLATION_QRC}
    ${QVMESSOCKET_QRC_RESOURCES}
    ${QVMESSOCKET_QM_FILES}
    )

if(QVMESSOCKET_QT6)
    qt6_add_executable(Qvmessocket ${GUI_TYPE} ${QVMESSOCKET_FULL_SOURCES})
else()
    add_executable(Qvmessocket ${GUI_TYPE} ${QVMESSOCKET_FULL_SOURCES})
endif()

target_include_directories(Qvmessocket PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}
    ${QNODEEDITOR_INCLUDE_PATH}
    ${Protobuf_INCLUDE_DIRS}
    )

target_link_libraries(Qvmessocket PUBLIC
    Qvmessocket_baselib
    ${QNODEEDITOR_LIBRARY}
    ${QVMESSOCKET_QRENCODE_LIBRARY}
    )

if(UNIX)
    include(cmake/platforms/linux.cmake)
elseif(WIN32)
    include(cmake/platforms/windows.cmake)
endif()

get_target_property(QVMESSOCKET_BASE_LINK_LIBS Qvmessocket_baselib LINK_LIBRARIES)
get_target_property(QVMESSOCKET_EXEC_LINK_LIBS Qvmessocket LINK_LIBRARIES)
