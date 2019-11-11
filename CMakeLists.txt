cmake_minimum_required (VERSION 3.10)

# Define the project
project(putih)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS " -std=c++14 -funroll-loops -O3 -march=native")

MESSAGE( [Main] " PROJECT_NAME = ${PROJECT_NAME}")
MESSAGE( [Main] " CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
MESSAGE( [Main] " CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
MESSAGE( [Main] " PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

set(HEADER_FILES
    src/ArgParser.h
    src/Connection.h
)

set(SOURCE_FILES 
    src/ArgParser.cc
    src/Connection.cc
)

include_directories(${PROJECT_SOURCE_DIR}/src/include)

# Add definition for library
add_library(Lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

# Add definition for the cmake-tutorial binary
add_executable(${PROJECT_NAME} src/Main.cc)
target_link_libraries(${PROJECT_NAME} PUBLIC Lib)