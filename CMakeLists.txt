cmake_minimum_required(VERSION 3.6)
project(trumpet)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

enable_language(CXX)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++14")

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.61.0 COMPONENTS property_tree)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
message(STATUS "CURL include directories: ${CURL_INCLUDE_DIRS}")
message(STATUS "CURL libraries: ${CURL_LIBRARIES}\n")

add_subdirectory(vendor)

set(TRUMPET_HEADER_FILES
        )

set(TRUMPET_SOURCE_FILES
        src/main.cpp
        )

add_executable(trumpet
        ${TRUMPET_SOURCE_FILES}
        ${TRUMPET_HEADER_FILES}
        ${CURLCPP_SOURCE_FILES}
        ${CURLCPP_HEADER_FILES}
        )

target_link_libraries(trumpet
        curlcpp
        ${CURL_LIBRARIES}
        )
