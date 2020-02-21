cmake_minimum_required(VERSION 3.14)
project(hashcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-W -Wall -Wextra --pedantic -Werror -fconcepts")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-comment -Wno-unused-function")

add_executable(hashcode
        src/main.cpp
        src/entities/book.cpp src/entities/book.h
        src/problem/problem_instance.cpp
        src/problem/problem_instance.h
        src/io/parser.cpp src/io/parser.h
        src/io/lexer.cpp src/io/lexer.h
        src/io/word.h
        src/entities/book_set.cpp
        src/entities/book_set.h
        src/entities/library_set.cpp
        src/entities/library_set.h
        src/entities/book.cpp src/entities/book.h src/entities/library.cpp src/entities/library.h)