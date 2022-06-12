set(CPACK_PACKAGE_VENDOR "Qvmessocket")
set(CPACK_PACKAGE_VERSION ${QCLASH_VERSION_STRING})
set(CPACK_PACKAGE_DESCRIPTION "Cross-platform Client written in Qt.")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/")
set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/assets/icons/qclash.ico")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

if(WIN32)
    set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION .)
    if(BUILD_NSIS)
        add_definitions(-DQV2RAY_NO_ASIDECONFIG)
        set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/assets/icons\\\\qclash.ico")
        set(CPACK_GENERATOR "NSIS")
        set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/assets/icons/qclash.ico")
        set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/assets/icons/qclash.ico")
        set(CPACK_NSIS_DISPLAY_NAME "Qvmessocket")
        set(CPACK_NSIS_PACKAGE_NAME "Qvmessocket")
        set(CPACK_NSIS_EXTRA_PREINSTALL_COMMANDS "
            ExecWait \\\"taskkill /f /im qvmessocket.exe\\\"
            ExecWait \\\"taskkill /f /im v2ray.exe\\\"
            ExecWait \\\"taskkill /f /im wv2ray.exe\\\"
            ExecWait \\\"taskkill /f /im xray.exe\\\"
            ")
        set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "
            CreateShortCut \\\"$DESKTOP\\\\Qv2ray.lnk\\\" \\\"$INSTDIR\\\\qvmessocket.exe\\\"
            CreateDirectory \\\"$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\Qv2ray\\\"
            CreateShortCut \\\"$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\Qv2ray\\\\Qv2ray.lnk\\\" \\\"$INSTDIR\\\\qvmessocket.exe\\\"
            WriteRegStr HKLM \\\"Software\\\\Microsoft\\\\Windows\\\\CurrentVersion\\\\Uninstall\\\\qvmessocket\\\" \\\"DisplayIcon\\\" \\\"$INSTDIR\\\\qvmessocket.exe\\\"
            WriteRegStr HKLM \\\"Software\\\\Microsoft\\\\Windows\\\\CurrentVersion\\\\Uninstall\\\\qvmessocket\\\" \\\"HelpLink\\\" \\\"https://github.com/vmessocket\\\"
            WriteRegStr HKLM \\\"Software\\\\Microsoft\\\\Windows\\\\CurrentVersion\\\\Uninstall\\\\qvmessocket\\\" \\\"InstallLocation\\\" \\\"$INSTDIR\\\"
            WriteRegStr HKLM \\\"Software\\\\Microsoft\\\\Windows\\\\CurrentVersion\\\\Uninstall\\\\qvmessocket\\\" \\\"URLUpdateInfo\\\" \\\"https://github.com/Qvmessocket/Qv2ray/releases\\\"
            WriteRegStr HKLM \\\"Software\\\\Microsoft\\\\Windows\\\\CurrentVersion\\\\Uninstall\\\\qvmessocket\\\" \\\"URLInfoAbout\\\" \\\"https://github.com/Qvmessocket/Qvmessocket\\\"
            ")
        set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS "
            ExecWait \\\"taskkill /f /im qvmessocket.exe\\\"
            Delete \\\"$DESKTOP\\\\Qv2ray.lnk\\\"
            Delete \\\"$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\Qv2ray\\\\Qv2ray.lnk\\\"
            RMDir \\\"$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\Qv2ray\\\"
            DeleteRegKey HKLM \\\"Software\\\\Microsoft\\\\Windows\\\\CurrentVersion\\\\Uninstall\\\\qvmessocket\\\"
            ")
        set(CPACK_PACKAGE_INSTALL_DIRECTORY "Qvmessocket")
    endif()
endif()

include(CPack)

set(DIRS "${CMAKE_BINARY_DIR}")

if(CMAKE_PREFIX_PATH)
    foreach(dir ${CMAKE_PREFIX_PATH})
        list(APPEND DIRS "${dir}/bin" "${dir}/lib")
    endforeach()
endif()

list(APPEND DIRS "${Qt6Core_DIR}/../..")

list(APPEND DIRS "/usr/local/lib")
list(APPEND DIRS "/usr/lib")

include(InstallRequiredSystemLibraries)

message(STATUS "APPS: ${APPS}")
message(STATUS "QT_PLUGINS: ${QT_PLUGINS}")
message(STATUS "DIRS: ${DIRS}")

install(CODE "
    include(BundleUtilities)
    fixup_bundle(\"${APPS}\"   \"\"   \"${DIRS}\")
    " COMPONENT Runtime)
