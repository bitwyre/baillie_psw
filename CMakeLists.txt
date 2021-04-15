cmake_minimum_required(VERSION 3.15)
project(baillie_psw)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES ${CMAKE_SOURCE_DIR}/baillie_bench.cpp 
            ${CMAKE_SOURCE_DIR}/baillie_test.hpp 
            ${CMAKE_SOURCE_DIR}/lucas_test.hpp
            ${CMAKE_SOURCE_DIR}/rabin_miller.hpp
            ${CMAKE_SOURCE_DIR}/benchmark.h)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libbenchmark.a pthread)