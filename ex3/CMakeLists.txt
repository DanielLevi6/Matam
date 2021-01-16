cmake_minimum_required(VERSION 3.0.0)
project(date_wrap VERSION 0.1.0)

set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors -L.")
set(MTM_FLAGS_RELEASE "$(MTM_FLAGS_DEBUG) -DNDEBUG")

set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

add_library(date partA/date.c partA/date.h)
add_executable(date_wrap ../partA/date_wrap.cpp ../provided/test_partA.cpp)
target_link_libraries(date_wrap -ldate)
