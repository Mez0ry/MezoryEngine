cmake_minimum_required(VERSION 3.9)

set(ProjectName MezoryEngine)

project(${ProjectName})

set_target_properties(${TARGET} PROPERTIES
                      CXX_STANDARD 17)
					  
add_executable(${ProjectName} ${ProjectName}/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
target_link_libraries(${ProjectName} glfw)

add_subdirectory(vendor/glad)
target_link_libraries(${ProjectName} glad)
#add_library(${ProjectName} ${ProjectName}/baseException.hpp)