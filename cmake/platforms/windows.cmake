find_package(OpenSSL REQUIRED)
target_link_libraries(qvmessocket_baselib wininet wsock32 ws2_32 user32 Rasapi32 Iphlpapi OpenSSL::SSL OpenSSL::Crypto Dbghelp)

install(TARGETS Qvmessocket RUNTIME DESTINATION .)

install(DIRECTORY ${CMAKE_BINARY_DIR}/winqt/ DESTINATION .)

set(APPS "\${CMAKE_INSTALL_PREFIX}/qvmessocket.exe")

include(cmake/deployment.cmake)

if(QVMESSOCKET_AUTO_DEPLOY)
    if(QVMESSOCKET_QT6)
        set(QVMESSOCKET_QtX_DIR ${Qt6_DIR})
    else()
        set(QVMESSOCKET_QtX_DIR ${Qt5_DIR})
    endif()
    add_custom_command(TARGET qvmessocket
        POST_BUILD
        COMMAND ${QVMESSOCKET_QtX_DIR}/../../../bin/windeployqt ${CMAKE_BINARY_DIR}/qvmessocket.exe --compiler-runtime --verbose 2 --dir ${CMAKE_BINARY_DIR}/winqt/)
endif()
