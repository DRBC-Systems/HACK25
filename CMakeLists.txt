cmake_minimum_required(VERSION 3.10)
project(Hack25)

# Set cmake version
set(CMAKE_CXX_STANDARD 17)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})

# Add the FLTK dir so cmake can find it
add_subdirectory(Externals/fltk)

# Include headers
include_directories(
    ${PROJECT_SOURCE_DIR}/Controller/include
    ${PROJECT_SOURCE_DIR}/Model/include
    ${PROJECT_SOURCE_DIR}/View/include
)

# Source files
file(GLOB_RECURSE CONTROLLER_SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/Controller/src/*.cpp)
file(GLOB_RECURSE MODEL_SOURCES      CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/Model/src/*.cpp)
file(GLOB_RECURSE VIEW_SOURCES       CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/View/src/*.cpp)

set(SOURCES
    ${CONTROLLER_SOURCES}
    ${MODEL_SOURCES}
    ${VIEW_SOURCES}
    ${PROJECT_SOURCE_DIR}/main.cpp
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link FLTK
target_link_libraries(${PROJECT_NAME} fltk fltk_images)