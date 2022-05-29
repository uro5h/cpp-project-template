cmake_minimum_required(VERSION 3.22)

project(app VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

find_package(fmt CONFIG REQUIRED)

# https://github.com/microsoft/vcpkg/commit/a6957ebf389648e2b2253e9b18f83d6a1508ab10#https://github.com/microsoft/vcpkg/commit/a6957ebf389648e2b2253e9b18f83d6a1508ab10
find_path(fmt_INCLUDE_DIR "fmt/format.h")

include_directories(
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/deps"
    "${CMAKE_CURRENT_SOURCE_DIR}/deps/fmtlog"
    "${fmt_INCLUDE_DIR}"
)

file(GLOB_RECURSE app_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(app "${app_SOURCES}")

target_link_libraries(app PRIVATE lib fmt::fmt)
