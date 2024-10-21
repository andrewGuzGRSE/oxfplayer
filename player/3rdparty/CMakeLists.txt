add_subdirectory(portaudio)
add_subdirectory(pugixml)

# signed-media-framework
set(SIGNED_MEDIA_FRAMEWORK_VERSION 0.0.0)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)
pkg_check_modules(GST REQUIRED gstreamer-1.0>=1.22 gstreamer-sdp-1.0>=1.22
                  gstreamer-video-1.0>=1.22 gstreamer-app-1.0>=1.22)

# signed-media-framework plugin
project(
  ${PLUGIN_NAME}
  VERSION ${SIGNED_MEDIA_FRAMEWORK_VERSION}
  LANGUAGES C)
add_library(${PLUGIN_NAME} STATIC
            ./signed-media-framework/lib/plugins/${PLUGIN_NAME}/plugin.c)
target_include_directories(
  ${PLUGIN_NAME}
  PUBLIC ./signed-media-framework/lib/src
  PRIVATE ${GLIB_INCLUDE_DIRS})
target_link_libraries(${PLUGIN_NAME} INTERFACE ${GLIB_LDFLAGS})

# signed-media-framework library
project(
  signed-media-framework
  VERSION ${SIGNED_MEDIA_FRAMEWORK_VERSION}
  LANGUAGES C)
file(GLOB SIGNED_MEDIA_FRAMEWORK_LIBRARY_SRC /signed-media-framework/lib/src/*)
add_library(signed-media-framework STATIC ${SIGNED_MEDIA_FRAMEWORK_LIBRARY_SRC})
target_link_libraries(signed-media-framework PRIVATE ${PLUGIN_NAME})

# signed-media-framework validation
project(
  signed-media-framework-validator
  VERSION ${SIGNED_MEDIA_FRAMEWORK_VERSION}
  LANGUAGES C)
add_executable(signed-media-framework-validator
               ./signed-media-framework/examples/apps/validator/main.c)
target_include_directories(
  signed-media-framework-validator
  PUBLIC ./signed-media-framework
  PRIVATE ${GLIB_INCLUDE_DIRS} ${GST_INCLUDE_DIRS})
target_compile_options(signed-media-framework-validator PRIVATE ${GST_CFLAGS})
target_link_libraries(
  signed-media-framework-validator
  INTERFACE ${GLIB_LDFLAGS}
  PRIVATE ${PLUGIN_NAME} signed-media-framework ${GST_LIBRARIES})
