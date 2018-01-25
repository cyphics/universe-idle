set (CMAKE_CXX_STANDARD 11)

add_custom_target(check)

#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

#Inclusion de la bibliothèque Hello
include_directories(../include)
#link_directories(${CMAKE_SOURCE_DIR}/../lib/)

#Add Catch lib
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE . )

#Configuration de l'exécutable
file(   GLOB_RECURSE
        source_files
        src/*.cpp
)


file(
    GLOB TEST_SOURCES src/*.cpp)



add_executable(test_app ${TEST_SOURCES})
target_link_libraries(test_app PRIVATE app_lib Catch)
add_dependencies(check test_app)
add_test(test_app ${CMAKE_CURRENT_BINARY_DIR}/bin/test_app)
