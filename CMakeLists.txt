cmake_minimum_required(VERSION 3.1)

project (libMaker C)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(uniLib)

target_link_libraries(${PROJECT_NAME}
    uni
)