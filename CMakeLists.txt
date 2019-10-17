cmake_minimum_required (VERSION 3.10)

# Define the project
project(putih)

set(CMAKE_CXX_FLAGS " -pthread -std=c++14 -funroll-loops -O3 -march=native")

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