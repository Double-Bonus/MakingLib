cmake_minimum_required(VERSION 3.1)

enable_testing ()
project (libMaker C CXX)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(uniLib)
add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME}
    uni
)
