# Set the library name
project (uni)

add_library(${PROJECT_NAME} src/uniLib.c)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)