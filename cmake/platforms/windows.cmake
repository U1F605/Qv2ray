find_package(OpenSSL REQUIRED)
target_link_libraries(Qvmessocket_baselib wininet wsock32 ws2_32 user32 Rasapi32 Iphlpapi OpenSSL::SSL OpenSSL::Crypto Dbghelp)

install(TARGETS Qvmessocket RUNTIME DESTINATION .)

install(DIRECTORY ${CMAKE_BINARY_DIR}/winqt/ DESTINATION .)

set(APPS "\${CMAKE_INSTALL_PREFIX}/Qvmessocket.exe")

include(cmake/deployment.cmake)

if(QCLASH_AUTO_DEPLOY)
    if(QVMESSOCKET_QT6)
        set(QVMESSOCKET_QtX_DIR ${Qt6_DIR})
    else()
        set(QVMESSOCKET_QtX_DIR ${Qt5_DIR})
    endif()
    add_custom_command(TARGET Qvmessocket
        POST_BUILD
        COMMAND ${QVMESSOCKET_QtX_DIR}/../../../bin/windeployqt ${CMAKE_BINARY_DIR}/qvmessocket.exe --compiler-runtime --verbose 2 --dir ${CMAKE_BINARY_DIR}/winqt/)
endif()
