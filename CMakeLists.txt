cmake_minimum_required(VERSION 3.10)
project(Hack25)

# Set cmake version
set(CMAKE_CXX_STANDARD 17)

# Add the FLTK dir so cmake can find it
# add_subdirectory(Externals/fltk)

# Include headers
include_directories(
    ${PROJECT_SOURCE_DIR}/Controller/include
    ${PROJECT_SOURCE_DIR}/Model/include
    ${PROJECT_SOURCE_DIR}/View/include
)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/Controller/src/*.cpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/Model/src/*.cpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/View/src/*.cpp)


# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${PROJECT_SOURCE_DIR}/main.cpp)

# Link FLTK
# target_link_libraries(${PROJECT_NAME} fltk fltk_images)