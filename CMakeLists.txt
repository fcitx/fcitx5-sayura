cmake_minimum_required(VERSION 3.6)

# The Project Name
project(fcitx5-sayura)

find_package(ECM REQUIRED 1.0.0)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
include(FeatureSummary)
include(GNUInstallDirs)
include(ECMUninstallTarget)

find_package(PkgConfig REQUIRED)
find_package(Fcitx5Core REQUIRED)
find_package(Gettext REQUIRED)

include("${FCITX_INSTALL_CMAKECONFIG_DIR}/Fcitx5Utils/Fcitx5CompilerSettings.cmake")

add_definitions(-DFCITX_GETTEXT_DOMAIN=\"fcitx5-sayura\" -D_GNU_SOURCE)

configure_file(config.h.in config.h
  IMMEDIATE @ONLY)

# add_subdirectory(po)
# add_subdirectory(src)
# add_subdirectory(data)
