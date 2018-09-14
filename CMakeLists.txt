cmake_minimum_required(VERSION 3.10)
project(WordsSort)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest)

set(SOURCE_FILES main.cpp gtests.cpp formatter/formatter.h)
add_executable(WordsSort ${SOURCE_FILES} formatter/formatter.cpp gtests.cpp)
target_link_libraries(WordsSort gtest gtest_main)

set(Boost_ADDITIONAL_VERSIONS "1.66" "1.66.0")
find_package(Boost REQUIRED COMPONENTS system filesystem)


target_include_directories(WordsSort PRIVATE ${Boost_INCLUDE_DIRS})

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)
