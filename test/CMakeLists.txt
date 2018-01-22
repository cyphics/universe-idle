cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

#Configuration du projet
project(test_bignum)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

#Inclusion de la bibliothèque Hello
include_directories(../include)
link_directories(${CMAKE_SOURCE_DIR}/../lib/)

#Add Catch lib
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE . )

#Configuration de l'exécutable
file(
        GLOB_RECURSE
        source_files
        ../src/*.cpp
)

add_executable(
        test_bignum
        ${source_files}
)

#Configuration de l'édition de liens
target_link_libraries(
        test_bignum
        bignum
        Catch
)
