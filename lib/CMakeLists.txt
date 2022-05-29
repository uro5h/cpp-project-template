cmake_minimum_required(VERSION 3.22)

project(lib VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

configure_file(
    "${PROJECT_SOURCE_DIR}/Config.h.in"
    "${PROJECT_BINARY_DIR}/Config.h"
)

find_package(fmt CONFIG REQUIRED)

# https://github.com/microsoft/vcpkg/commit/a6957ebf389648e2b2253e9b18f83d6a1508ab10
find_path(fmt_INCLUDE_DIR "fmt/format.h")

add_library(lib SHARED)

include_directories(
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/deps"
    "${CMAKE_CURRENT_SOURCE_DIR}/deps/fmtlog"
    "${fmt_INCLUDE_DIR}"
)

file(GLOB_RECURSE lib_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp"
)

file(GLOB_RECURSE lib_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.hpp"
)

target_sources(lib
    PRIVATE ${lib_SOURCES}
    PUBLIC ${lib_HEADERS}
    INTERFACE FILE_SET HEADERS BASE_DIRS "${PROJECT_SOURCE_DIR}" ${lib_HEADERS}
)

target_link_libraries(lib PUBLIC fmt::fmt)
