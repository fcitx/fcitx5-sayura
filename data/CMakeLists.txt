install(FILES sayura.svg DESTINATION "${CMAKE_INSTALL_DATADIR}/icons/hicolor/scalable/apps/")
set(sizes 16 24 32 48 64 128 192)
foreach(size ${sizes})
  install(FILES "sayura${size}.png"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/icons/hicolor/${size}x${size}/apps/"
    RENAME fcitx-sayura.png)
endforeach()
