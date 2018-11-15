cmake_minimum_required(VERSION 3.12)
project(cpp_duktape_example)

set(CMAKE_CXX_STANDARD 17)

include_directories(dependencies/duktape)
file(GLOB_RECURSE HEADER_FILES "include/*.hpp" "include/*.h" dependencies/*.c)
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.c" dependencies/sqlite3/*.c)

add_library(DuktapeCpp STATIC ${SOURCE_FILES} ${HEADER_FILES})

### Link desktop specific
if("${CMAKE_SYSTEM}" MATCHES "Linux" OR "${CMAKE_SYSTEM}" MATCHES "Darwin-*")
    add_subdirectory(test)
endif()