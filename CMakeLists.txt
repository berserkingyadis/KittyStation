cmake_minimum_required(VERSION 3.0)
project(KittyStation CXX)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(KittyStation ${SOURCE_FILES})


find_package(SDL2 REQUIRED)

IF (WIN32)
include_directories(KittyStation ${SDL2_INCLUDE_DIRS})
target_link_libraries(KittyStation ${SDL2_LIBRARIES})
ELSE()
target_link_libraries(KittyStation SDL2::SDL2)
ENDIF()

if(MSVC)
  target_compile_options(KittyStation PRIVATE /W4)
else()
  target_compile_options(KittyStation PRIVATE -Wall -Wextra -pedantic)
endif()



