cmake_minimum_required(VERSION 3.10)
project(SimpleDB)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src/core)

add_executable(repl
    src/core/main.cpp
    src/core/input_buffer.cpp
    src/core/meta_command.cpp
    src/core/statement.cpp
    src/core/table.cpp
    src/core/row.cpp
)
