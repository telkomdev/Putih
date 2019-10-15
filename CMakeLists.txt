cmake_minimum_required (VERSION 3.10)

# Define the project
project(Putih)

include_directories(${PROJECT_SOURCE_DIR}/src/include)

# Add definition for library
add_library(Lib
    src/ArgParser.cc
    src/Connection.cc
)

# Add definition for the cmake-tutorial binary
add_executable(${PROJECT_NAME} src/Main.cc)
target_link_libraries(${PROJECT_NAME} PUBLIC Lib)