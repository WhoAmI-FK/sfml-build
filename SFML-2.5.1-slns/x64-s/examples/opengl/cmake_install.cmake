# Install script for directory: C:/Users/User/source/repos/sfml-try/SFML-2.5.1-src/examples/opengl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/SFML")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "examples" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./examples/opengl" TYPE EXECUTABLE FILES "C:/Users/User/source/repos/sfml-try/SFML-2.5.1-slns/x64-s/examples/opengl/Debug/opengl-d.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./examples/opengl" TYPE EXECUTABLE FILES "C:/Users/User/source/repos/sfml-try/SFML-2.5.1-slns/x64-s/examples/opengl/Release/opengl.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./examples/opengl" TYPE EXECUTABLE FILES "C:/Users/User/source/repos/sfml-try/SFML-2.5.1-slns/x64-s/examples/opengl/MinSizeRel/opengl.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./examples/opengl" TYPE EXECUTABLE FILES "C:/Users/User/source/repos/sfml-try/SFML-2.5.1-slns/x64-s/examples/opengl/RelWithDebInfo/opengl.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./examples/opengl" TYPE FILE FILES "C:/Users/User/source/repos/sfml-try/SFML-2.5.1-src/examples/opengl/OpenGL.cpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./examples/opengl" TYPE DIRECTORY FILES "C:/Users/User/source/repos/sfml-try/SFML-2.5.1-src/examples/opengl/resources")
endif()

