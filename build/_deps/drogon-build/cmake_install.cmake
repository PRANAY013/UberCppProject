# Install script for directory: /Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/trantor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/examples/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/drogon_ctl/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/libdrogon.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrogon.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrogon.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrogon.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/drogon" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/Attribute.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/CacheMap.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/Cookie.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/DrClassMap.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/DrObject.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/DrTemplate.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/DrTemplateBase.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpAppFramework.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpBinder.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpClient.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpController.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpFilter.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpMiddleware.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpRequest.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/RequestStream.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpResponse.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpSimpleController.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpTypes.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/HttpViewData.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/IntranetIpFilter.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/IOThreadStorage.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/LocalHostFilter.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/MultiPart.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/NotFound.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/Session.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/UploadFile.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/WebSocketClient.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/WebSocketConnection.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/WebSocketController.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/drogon.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/lib/inc/drogon/version.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/drogon_callbacks.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/PubSubService.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/drogon_test.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/RateLimiter.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/exports/drogon/exports.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/drogon/orm" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/ArrayParser.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/BaseBuilder.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/Criteria.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/DbClient.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/DbConfig.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/DbListener.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/DbTypes.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/Exception.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/Field.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/FunctionTraits.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/Mapper.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/CoroMapper.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/Result.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/ResultIterator.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/Row.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/RowIterator.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/SqlBinder.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/orm_lib/inc/drogon/orm/RestfulController.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/drogon/nosql" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/nosql_lib/redis/inc/drogon/nosql/RedisClient.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/nosql_lib/redis/inc/drogon/nosql/RedisResult.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/nosql_lib/redis/inc/drogon/nosql/RedisSubscriber.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/nosql_lib/redis/inc/drogon/nosql/RedisException.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/drogon/utils" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/coroutine.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/FunctionTraits.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/HttpConstraint.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/OStringStream.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/Utilities.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/drogon/utils/monitoring" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring/Counter.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring/Metric.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring/Registry.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring/Collector.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring/Sample.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring/Gauge.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/utils/monitoring/Histogram.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/drogon/plugins" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/Plugin.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/Redirector.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/SecureSSLRedirector.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/AccessLogger.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/RealIpResolver.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/Hodor.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/SlashRemover.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/GlobalFilters.h"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/lib/inc/drogon/plugins/PromExporter.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Drogon" TYPE FILE FILES
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/CMakeFiles/DrogonConfig.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/DrogonConfigVersion.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/FindUUID.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/FindJsoncpp.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/FindSQLite3.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/FindMySQL.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/Findpg.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/FindBrotli.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/Findcoz-profiler.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/FindHiredis.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake_modules/FindFilesystem.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake/DrogonUtilities.cmake"
    "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-src/cmake/ParseAndAddDrogonTests.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Drogon/DrogonTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Drogon/DrogonTargets.cmake"
         "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/CMakeFiles/Export/9fe51f2b716a6bd37518a903e3e9a4cf/DrogonTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Drogon/DrogonTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Drogon/DrogonTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Drogon" TYPE FILE FILES "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/CMakeFiles/Export/9fe51f2b716a6bd37518a903e3e9a4cf/DrogonTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Drogon" TYPE FILE FILES "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/CMakeFiles/Export/9fe51f2b716a6bd37518a903e3e9a4cf/DrogonTargets-noconfig.cmake")
  endif()
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/pranay/Pranay/PROG/UberCppProject/build/_deps/drogon-build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
