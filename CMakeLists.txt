cmake_minimum_required(VERSION 3.31)
project(dummy_lang)

set(CMAKE_CXX_STANDARD 20)

add_executable(dummy_lang
        src/main.cpp
        src/Lexer.cpp
)

target_include_directories(dummy_lang PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
