cmake_minimum_required(VERSION 3.14)
project(hashcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-W -Wall -Wextra --pedantic -Werror -fconcepts")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-comment -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter")

add_executable(hashcode
        src/main.cpp
        src/entities/book.cpp src/entities/book.h
        src/problem/problem_instance.cpp
        src/problem/problem_instance.h
        src/io/parser.cpp src/io/parser.h
        src/collections/bookset.cpp
        src/collections/bookset.h
        src/collections/library_set.cpp
        src/collections/library_set.h
        src/entities/book.cpp src/entities/book.h
        src/entities/library.cpp src/entities/library.h
        src/problem/heuristic.h
        src/entities/def.h
        src/statistics/bookset_statistics.cpp src/statistics/bookset_statistics.h
        src/statistics/basic_info.h)