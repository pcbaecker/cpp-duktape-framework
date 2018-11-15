cmake_minimum_required(VERSION 3.12)
project(cpp_duktape_example_Test)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HEADER_FILES "./*.hpp")
file(GLOB_RECURSE SOURCE_FILES "./*.cpp")

add_executable(DuktapeCppTest ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries (DuktapeCppTest DuktapeCpp)