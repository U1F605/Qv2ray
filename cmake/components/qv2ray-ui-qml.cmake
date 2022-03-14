set(QVMESSOCKET_QML_BASEDIR ${CMAKE_SOURCE_DIR}/src/ui/qml)
set(QVMESSOCKET_QML_SOURCES
    ${QVMESSOCKET_QML_BASEDIR}/qmlresx.qrc
    ${QVMESSOCKET_QML_BASEDIR}/Qv2rayQMLApplication.hpp
    ${QVMESSOCKET_QML_BASEDIR}/Qv2rayQMLApplication.cpp
    ${QVMESSOCKET_QML_BASEDIR}/Qv2rayQMLProperty.cpp
    ${QVMESSOCKET_QML_BASEDIR}/Qv2rayQMLProperty.hpp
    )

if(QVMESSOCKET_QML_LIVE_UPDATE)
    add_definitions(-DQV2RAY_QMLLIVE_DEBUG=1)
    find_library(QMLLIVE_LIBS qmllive)
    link_libraries(-lqmllive)
endif()
