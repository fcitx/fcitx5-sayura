set(SAYURA_SOURCES
    engine.cpp
)
add_library(sayura MODULE ${SAYURA_SOURCES})
target_link_libraries(sayura Fcitx5::Core Fcitx5::Config)
set_target_properties(sayura PROPERTIES PREFIX "")
install(TARGETS sayura DESTINATION "${CMAKE_INSTALL_LIBDIR}/fcitx5")
fcitx5_translate_desktop_file(sayura.conf.in sayura.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/sayura.conf" DESTINATION "${CMAKE_INSTALL_DATADIR}/fcitx5/inputmethod")
fcitx5_translate_desktop_file(sayura-addon.conf.in sayura-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/sayura-addon.conf" RENAME sayura.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")
