set(QVMESSOCKET_CLI_BASEDIR ${CMAKE_SOURCE_DIR}/src/ui/cli)
add_definitions(-DQAPPLICATION_CLASS=QCoreApplication)

set(QVMESSOCKET_CLI_SOURCES
    ${QVMESSOCKET_CLI_BASEDIR}/Qv2rayCliApplication.hpp
    ${QVMESSOCKET_CLI_BASEDIR}/Qv2rayCliApplication.cpp)
