cmake_minimum_required(VERSION 3.13)
##############################################################################################################

project(fty_scripts_rest
  VERSION 1.0.0
  DESCRIPTION "Scripts REST API for 42ity project"
  LANGUAGES CXX)

# Workaround '-' vs '_'
set(PROJECT_NAME_HYPHEN fty-scripts-rest)

##############################################################################################################
find_package(fty-cmake PATHS ${CMAKE_BINARY_DIR}/fty-cmake)
##############################################################################################################

# Define the servlet
etn_target(shared ${PROJECT_NAME}
  SOURCES
    src/*.cc
  INCLUDE_DIRS
    include
  USES
    fty-cmake-rest
    cxxtools
    tntnet
    fty_common
    fty_common_logging
    fty_common_rest
    fty_common_mlm
)

set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Get the ecpp
file(GLOB ECPP_FILES
  ecpp/*.ecpp
)

# Transform ecpp files
fty_ecppbuilder(
  TARGET ${PROJECT_NAME}
  WORKDIR src
  ECPP
    ${ECPP_FILES}
)

# Create var/lib/fty/fty-scripts-rest
# -- see debian postinst --
# owner & privileges:
#      d /var/lib/fty/fty-scripts-rest 2755 root www-data
#      x /var/lib/fty/fty-scripts-rest/*
#install(DIRECTORY DESTINATION ${CMAKE_INSTALL_FULL_LOCALSTATEDIR}/lib/fty/${PROJECT_NAME_HYPHEN})

# Install tntnet mapping files in etc/tntnet/bios.d/
install(FILES ${PROJECT_SOURCE_DIR}/resources/40_scripts-rest.xml DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/tntnet/bios.d/)
