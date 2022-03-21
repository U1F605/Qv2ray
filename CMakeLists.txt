cmake_minimum_required(VERSION 3.10.1)

file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/VERSION" QVMESSOCKET_VERSION)
file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/BUILDVERSION" QVMESSOCKET_BUILD_VERSION)
file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/VERSIONSUFFIX" QVMESSOCKET_VERSION_SUFFIX)

set(QVMESSOCKET_VERSION_STRING "${QVMESSOCKET_VERSION}${QVMESSOCKET_VERSION_SUFFIX}")
project(qvmessocket)

macro(QVLOG MSG)
    set(QVMESSOCKET_BUILD_STATS "${QVMESSOCKET_BUILD_STATS}${MSG}: ${${MSG}}\r\n")
endmacro()

set(VERSION_LIST ${QVMESSOCKET_VERSION})
string(REPLACE "." ";" VERSION_LIST ${VERSION_LIST})
separate_arguments(VERSION_LIST)

list(GET VERSION_LIST 0 CMAKE_PROJECT_VERSION_MAJOR)
list(GET VERSION_LIST 1 CMAKE_PROJECT_VERSION_MINOR)
list(GET VERSION_LIST 2 CPACK_PACKAGE_VERSION_PATCH)

add_definitions(-DQVMESSOCKET_VERSION_MAJOR=${CMAKE_PROJECT_VERSION_MAJOR})
add_definitions(-DQVMESSOCKET_VERSION_MINOR=${CMAKE_PROJECT_VERSION_MINOR})
add_definitions(-DQVMESSOCKET_VERSION_BUGFIX=${CPACK_PACKAGE_VERSION_PATCH})
add_definitions(-DQVMESSOCKET_VERSION_BUILD=${QVMESSOCKET_BUILD_VERSION})
add_definitions(-DQVMESSOCKET_VERSION_STRING="${QVMESSOCKET_VERSION_STRING}")

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
        NAME               "Qvmessocket"
        BUNDLE             "VMESSOCKET Project Family"
        ICON               "${CMAKE_SOURCE_DIR}/assets/icons/qv2ray.ico"
        VERSION_MAJOR      ${CMAKE_PROJECT_VERSION_MAJOR}
        VERSION_MINOR      ${CMAKE_PROJECT_VERSION_MINOR}
        VERSION_PATCH      ${CPACK_PACKAGE_VERSION_PATCH}
        VERSION_REVISION   ${QVMESSOCKET_BUILD_VERSION}
        COMPANY_NAME       "VMESSOCKET BDFL-U1F605"
        COMPANY_COPYRIGHT  "VMESSOCKET BDFL-U1F605"
        FILE_DESCRIPTION   "Qvmessocket Main Application"
        )
    add_definitions(-DUNICODE -D_UNICODE -DNOMINMAX)
    set(GUI_TYPE WIN32)
    add_compile_options("/utf-8")
    add_compile_options("/std:c++17")
    add_definitions(-D_WIN32_WINNT=0x600 -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS)
    if(CMAKE_CL_64)
        set(QVMESSOCKET_PLATFORM_LIBS_PREFIX ${CMAKE_SOURCE_DIR}/libs/x64-windows/)
    else()
        set(QVMESSOCKET_PLATFORM_LIBS_PREFIX ${CMAKE_SOURCE_DIR}/libs/x86-windows/)
    endif()
    include(cmake/platforms/prefixes.cmake)
endif()

if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.17.0")
    cmake_policy(SET CMP0100 NEW)
endif()

message("Qvmessocket Version: ${QVMESSOCKET_VERSION_STRING}")
message("Qvmessocket Build Version: ${QVMESSOCKET_BUILD_VERSION}")

option(QVMESSOCKET_AUTO_DEPLOY "Automatically run deploy command after build" ON)

option(BUILD_TESTING "Build Tests" OFF)

set(QVMESSOCKET_DEFAULT_VASSETS_PATH "unset" CACHE STRING "Default assets path")

set(QVMESSOCKET_DEFAULT_VCORE_PATH "unset" CACHE STRING "Default core path")

option(QVMESSOCKET_DISABLE_AUTO_UPDATE "Disable Update Checker" OFF)

option(QVMESSOCKET_HAS_BUILTIN_PLUGINS "Build with builtin plugins" ON)

option(QVMESSOCKET_EMBED_TRANSLATIONS "Embed Translations" OFF)
option(QVMESSOCKET_HAS_SINGLEAPPLICATION "Build With SingleApplication" ON)

set(QVMESSOCKET_UI_TYPE "QWidget" CACHE STRING "GUI Component")

option(QVMESSOCKET_QT6 "Use Qt6" OFF)

if(QVMESSOCKET_UI_TYPE STREQUAL "QWidget")
    set(QVMESSOCKET_USE_QWIDGET ON)
elseif(QVMESSOCKET_UI_TYPE STREQUAL "CLI")
    set(QVMESSOCKET_USE_QWIDGET OFF)
endif()

if(QVMESSOCKET_HAS_SINGLEAPPLICATION)
    set(QV2RAY_SINGLEAPPLICATION_PROVIDER "module" CACHE STRING "SingleApplication Provider")
    QVLOG(QV2RAY_SINGLEAPPLICATION_PROVIDER)
endif()

if(QVMESSOCKET_USE_QWIDGET)
    option(QV2RAY_HAS_BUILTIN_THEMES "Build with built-in themes" ON)
    set(QVMESSOCKET_QNODEEDITOR_PROVIDER "module" CACHE STRING "QNodeEditor Provider")
    QVLOG(QV2RAY_HAS_BUILTIN_THEMES)
    QVLOG(QVMESSOCKET_QNODEEDITOR_PROVIDER)
endif()

if(QVMESSOCKET_QT6)
    cmake_policy(SET CMP0072 NEW)
    set(QV_QT_MAJOR_VERSION 6)
    set(QV_QT_MINOR_VERSION 0)
    set(QV_QT_LIBNAME Qt6)
    add_definitions(-DQV2RAY_QT6=1)
else()
    set(QV_QT_MAJOR_VERSION 5)
    set(QV_QT_MINOR_VERSION 11)
    set(QV_QT_LIBNAME Qt5)
endif()

if(QVMESSOCKET_DEFAULT_VCORE_PATH AND NOT QVMESSOCKET_DEFAULT_VCORE_PATH STREQUAL "unset")
    add_definitions(-DQVMESSOCKET_DEFAULT_VCORE_PATH="${QVMESSOCKET_DEFAULT_VCORE_PATH}")
endif()
if(QVMESSOCKET_DEFAULT_VASSETS_PATH AND NOT QVMESSOCKET_DEFAULT_VASSETS_PATH STREQUAL "unset")
    add_definitions(-DQMESSOCKET_DEFAULT_VASSETS_PATH="${QVMESSOCKET_DEFAULT_VASSETS_PATH}")
endif()

# ==================================================================================
# Embed Translations, Translation Search Path
# ==================================================================================
set(QV2RAY_TRANSLATION_PATH "unset" CACHE STRING "Qv2ray translations path")
if(QV2RAY_TRANSLATION_PATH AND NOT QV2RAY_TRANSLATION_PATH STREQUAL "unset")
    add_definitions(-DQV2RAY_TRANSLATION_PATH="${QV2RAY_TRANSLATION_PATH}")
endif()
if(QVMESSOCKET_EMBED_TRANSLATIONS)
    add_definitions(-DQ_EMBED_TRANSLATIONS)
    configure_file(translations/translations.qrc ${CMAKE_BINARY_DIR} COPYONLY)
    set(QVMESSOCKET_EMBED_TRANSLATION_QRC ${CMAKE_BINARY_DIR}/translations.qrc)
endif()

# ==================================================================================
# Disable Auto Update
# ==================================================================================
if(QVMESSOCKET_DISABLE_AUTO_UPDATE)
    add_definitions(-DDISABLE_AUTO_UPDATE)
endif()

# ==================================================================================
# Qv2ray Build Info
# ==================================================================================
if(QV2RAY_BUILD_INFO)
    set(_QV2RAY_BUILD_INFO_STR_ "${QV2RAY_BUILD_INFO}")
elseif(DEFINED ENV{_QV2RAY_BUILD_INFO_})
    set(_QV2RAY_BUILD_INFO_STR_ "$ENV{_QV2RAY_BUILD_INFO_}")
else()
    set(_QV2RAY_BUILD_INFO_STR_ "Qv2ray from manual build")
endif()

if(QV2RAY_BUILD_EXTRA_INFO)
    set(_QV2RAY_BUILD_EXTRA_INFO_STR_ "${QV2RAY_BUILD_EXTRA_INFO}")
elseif(DEFINED ENV{_QV2RAY_BUILD_EXTRA_INFO_})
    set(_QV2RAY_BUILD_EXTRA_INFO_STR_ "$ENV{_QV2RAY_BUILD_EXTRA_INFO_}")
else()
    set(_QV2RAY_BUILD_EXTRA_INFO_STR_ "${QVMESSOCKET_VERSION_STRING}:${QVMESSOCKET_BUILD_VERSION}")
endif()

set(QV2RAY_BUILD_INFO ${_QV2RAY_BUILD_INFO_STR_})
set(QV2RAY_BUILD_EXTRA_INFO ${_QV2RAY_BUILD_EXTRA_INFO_STR_})

add_definitions(-D_QV2RAY_BUILD_INFO_STR_="${_QV2RAY_BUILD_INFO_STR_}")
add_definitions(-D_QV2RAY_BUILD_EXTRA_INFO_STR_="${_QV2RAY_BUILD_EXTRA_INFO_STR_}")
message("Qv2ray Version: ${_QV2RAY_BUILD_INFO_STR_} - ${_QV2RAY_BUILD_EXTRA_INFO_STR_}")

# ==================================================================================
# 3rdparty Sources
# ==================================================================================
include(cmake/libuv.cmake)
include(cmake/libcurl.cmake)
include(cmake/libsemver.cmake)
include(cmake/protobuf.cmake)
include(cmake/backend.cmake)
include(3rdparty/QJsonStruct/QJsonStruct.cmake)

# ==================================================================================
# Qv2ray Base, Qt Libraries, Qv2ray GUI Libraries, libThreads
# ==================================================================================
find_package(Threads REQUIRED)
find_package(${QV_QT_LIBNAME} ${QV_QT_MAJOR_VERSION}.${QV_QT_MINOR_VERSION} COMPONENTS Core Network REQUIRED)
list(APPEND QVMESSOCKET_QT_LIBS ${QV_QT_LIBNAME}::Core ${QV_QT_LIBNAME}::Network)

cmake_policy(SET CMP0071 NEW)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(QVMESSOCKET_USE_QWIDGET)
    find_package(${QV_QT_LIBNAME} ${QV_QT_MAJOR_VERSION}.${QV_QT_MINOR_VERSION} COMPONENTS Widgets Svg Gui REQUIRED)
    list(APPEND QVMESSOCKET_QT_LIBS
        ${QV_QT_LIBNAME}::Widgets
        ${QV_QT_LIBNAME}::Svg
        ${QV_QT_LIBNAME}::Gui)
    set(_QV2RAY_HAS_GUI_INTERNAL_ ON)
endif()

include(cmake/components/base.cmake)
include(src/plugin-interface/QvPluginInterface.cmake)

if(QVMESSOCKET_HAS_SINGLEAPPLICATION)
    include(cmake/singleapplication.cmake)
else()
    add_definitions(-DQVMESSOCKET_NO_SINGLEAPPLICATON)
endif()

add_library(qv2ray_baselib STATIC
    ${QVMESSOCKET_BASE_SOURCES}
    ${SINGLEAPPLICATION_SOURCES}
    ${QVPLUGIN_INTERFACE_HEADERS}
    ${LIBSEMVER_SOURCES}
    ${PROTO_SRCS}
    ${PROTO_HDRS}
    ${API_GRPC_SRCS}
    ${API_PROTO_SRCS}
    )

target_link_libraries(qv2ray_baselib
    ${QVMESSOCKET_QT_LIBS}
    ${QVMESSOCKET_PROTOBUF_LIBRARY}
    ${QVMESSOCKET_BACKEND_LIBRARY}
    ${LibUV_LIBRARIES}
    ${CURL_LIBRARIES}
    ${SINGLEAPPLICATION_LIBRARY}
    Threads::Threads
    )

target_include_directories(qv2ray_baselib PUBLIC
    ${CMAKE_BINARY_DIR}
    ${LibUV_INCLUDE_DIR}
    ${SINGLEAPPLICATION_DIR}
    ${CURL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Protobuf_INCLUDE_DIRS}
    )

# ==================================================================================
# Qv2ray Builtin Plugins
# ==================================================================================
if(QVMESSOCKET_HAS_BUILTIN_PLUGINS)
    include(src/plugins/protocols/QvPlugin-BuiltinProtocolSupport.cmake)
    include(src/plugins/subscription-adapters/QvPlugin-BuiltinSubscriptionAdapters.cmake)
    #include(src/plugins/utils/QvPlugin-BuiltinUtils.cmake)
endif()

# ==================================================================================
# Qv2ray UI Frontend
# ==================================================================================
if(_QV2RAY_HAS_GUI_INTERNAL_)
    add_definitions(-DQV2RAY_GUI)
    include(cmake/qrencode.cmake)

    include(cmake/components/ui.cmake)
    list(APPEND QVMESSOCKET_UI_SOURCES ${QVMESSOCKET_UI_COMMON_SOURCES})

    include(src/plugin-interface/QvGUIPluginInterface.cmake)
    list(APPEND QVMESSOCKET_UI_SOURCES ${QVGUIPLUGIN_INTERFACE_HEADERS})
    
    if(QVMESSOCKET_USE_QWIDGET)
        add_definitions(-DQV2RAY_GUI_QWIDGETS)
        include(cmake/components/ui-widget.cmake)
        list(APPEND QVMESSOCKET_UI_SOURCES ${QVMESSOCKET_UI_WIDGET_SOURCES})
        #
        if (QV2RAY_HAS_BUILTIN_THEMES)
            include(3rdparty/uistyles/uistyles.cmake)
            list(APPEND QVMESSOCKET_QRC_RESOURCES ${UISTYLE_QRCS})
        endif()
        #
        include(cmake/qnodeeditor.cmake)
        list(APPEND QVMESSOCKET_QRC_RESOURCES ${QNODEEDITOR_QRC_RESOURCES})
    endif()
endif()

include(cmake/translations.cmake)

list(APPEND QVMESSOCKET_QRC_RESOURCES
    ${CMAKE_SOURCE_DIR}/resources.qrc
    ${CMAKE_SOURCE_DIR}/resources.new.qrc
    )

set(QV2RAY_FULL_SOURCES
    ${QVMESSOCKET_RC}
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    ${QVMESSOCKET_UI_SOURCES}
    ${QVMESSOCKET_EMBED_TRANSLATION_QRC}
    ${QVMESSOCKET_QRC_RESOURCES}
    ${QVMESSOCKET_QM_FILES}
    )

if(QVMESSOCKET_QT6)
    qt6_add_executable(qv2ray ${GUI_TYPE} ${QV2RAY_FULL_SOURCES})
else()
    add_executable(qv2ray ${GUI_TYPE} ${QV2RAY_FULL_SOURCES})
endif()

target_include_directories(qv2ray PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}
    ${QNODEEDITOR_INCLUDE_PATH}
    ${Protobuf_INCLUDE_DIRS}
    )

target_link_libraries(qv2ray PUBLIC
    qv2ray_baselib
    ${QNODEEDITOR_LIBRARY}
    ${QVMESSOCKET_QRENCODE_LIBRARY}
    )

if (BUILD_TESTING)
    include(CTest)
    add_subdirectory(test)
endif()

if(UNIX AND NOT APPLE AND NOT WIN32 AND NOT ANDROID)
    include(cmake/platforms/linux.cmake)
elseif(WIN32)
    include(cmake/platforms/windows.cmake)
endif()

get_target_property(QVMESSOCKET_BASE_LINK_LIBS qv2ray_baselib LINK_LIBRARIES)
get_target_property(QVMESSOCKET_EXEC_LINK_LIBS qv2ray LINK_LIBRARIES)
message("${QVMESSOCKET_BUILD_STATS}")
