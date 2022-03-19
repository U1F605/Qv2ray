set(QVMESSOCKET_UI_COMMON_BASEDIR ${CMAKE_SOURCE_DIR}/src/ui/common)
add_definitions(-DQAPPLICATION_CLASS=QApplication)

set(QVMESSOCKET_UI_COMMON_SOURCES
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/QRCodeHelper.cpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/QRCodeHelper.hpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/autolaunch/QvAutoLaunch.hpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/autolaunch/QvAutoLaunch.cpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/LogHighlighter.hpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/LogHighlighter.cpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/QvMessageBus.hpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/QvMessageBus.cpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/darkmode/DarkmodeDetector.cpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/darkmode/DarkmodeDetector.hpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/speedchart/speedwidget.cpp
    ${QVMESSOCKET_UI_COMMON_BASEDIR}/speedchart/speedwidget.hpp
    )
