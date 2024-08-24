cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME ONVIFPlayer)

project(${PROJECT_NAME} VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    # Find includes in the build directories
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CONFIGURATION_TYPES Debug Release)

# Supress ZERO_CHECK project generation
set(CMAKE_SUPPRESS_REGENERATION true)

# Add a compiler flag
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Make this a GUI application on Windows
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

# Allow test - muts be in root CMakeLists.txt
enable_testing(true)

# Find Qt
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED)
find_package(Qt5 COMPONENTS Test REQUIRED)
# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Add 3rd party as submodules
add_subdirectory(3rdparty)

# Add source code
add_subdirectory(src)

if (WIN32) 
# Add custom actions that will copy compiled data to ISS installer folder

add_custom_target(create-install-folder ALL COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/../setup/input)

add_dependencies(${PROJECT_NAME} create-install-folder)
    
add_custom_target(copy-PortAudio ALL COMMAND ${CMAKE_COMMAND} -E copy copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_CURRENT_SOURCE_DIR}/../setup/input)

endif()