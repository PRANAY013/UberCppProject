# Install script for directory: /Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/libtrantor.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtrantor.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtrantor.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtrantor.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/trantor" TYPE FILE FILES "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/exports/trantor/exports.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/trantor/net" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/EventLoop.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/EventLoopThread.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/EventLoopThreadPool.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/InetAddress.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/TcpClient.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/TcpConnection.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/TcpServer.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/AsyncStream.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/callbacks.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/Resolver.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/Channel.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/Certificate.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/net/TLSPolicy.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/trantor/utils" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/AsyncFileLogger.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/ConcurrentTaskQueue.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/Date.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/Funcs.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/LockFreeQueue.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/LogStream.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/Logger.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/MsgBuffer.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/NonCopyable.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/ObjectPool.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/SerialTaskQueue.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/TaskQueue.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/TimingWheel.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/trantor/utils/Utilities.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Trantor" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/CMakeFiles/TrantorConfig.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/TrantorConfigVersion.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/cmake_modules/Findc-ares.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/trantor/cmake_modules/FindBotan.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Trantor/TrantorTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Trantor/TrantorTargets.cmake"
         "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/CMakeFiles/Export/e2741f8d78b158992c2d7ed6a282eae4/TrantorTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Trantor/TrantorTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Trantor/TrantorTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Trantor" TYPE FILE FILES "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/CMakeFiles/Export/e2741f8d78b158992c2d7ed6a282eae4/TrantorTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Trantor" TYPE FILE FILES "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/CMakeFiles/Export/e2741f8d78b158992c2d7ed6a282eae4/TrantorTargets-noconfig.cmake")
  endif()
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
