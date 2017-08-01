cmake_minimum_required(VERSION 2.8.3)
project(fzi_icl_core)

SET(ICMAKER_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/icmaker")
INCLUDE(${ICMAKER_DIRECTORY}/CMakeLists.txt)

ADD_SUBDIRECTORY (src/icl_core)

# Install catkin package.xml
install(FILES package.xml DESTINATION share/icl_core)
