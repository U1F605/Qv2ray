install(TARGETS Qvmessocket RUNTIME DESTINATION bin)
install(FILES ${CMAKE_SOURCE_DIR}/assets/qvmessocket.metainfo.xml DESTINATION share/metainfo)
install(FILES ${CMAKE_SOURCE_DIR}/assets/qvmessocket.desktop DESTINATION share/applications)
install(FILES ${CMAKE_SOURCE_DIR}/assets/icons/qv2ray.svg DESTINATION share/icons/hicolor/scalable/apps)

set(QVMESSOCKET_ICON_DIMENSIONS 16 22 32 48 64 128 256 512 1024)

foreach(d ${QVMESSOCKET_ICON_DIMENSIONS})
    install(FILES assets/icons/qv2ray.${d}.png
        DESTINATION share/icons/hicolor/${d}x${d}/apps
        RENAME qv2ray.png)
endforeach(d)
