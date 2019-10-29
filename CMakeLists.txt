cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TSIS-LAB03)

add_library(
  ${PROJECT_NAME}
  STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Annealing_simulation_algorithm.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(main ./sources/main.cpp)

target_include_directories(
main
PUBLIC
 ${CMAKE_CURRENT_SOURCE_DIR}/include
)

 target_link_libraries(main ${PROJECT_NAME})
