cmake_minimum_required(VERSION 3.9)

set(ProjectName MezoryEngine)

project(${ProjectName})

set (CMAKE_CXX_STANDARD 17)
							  #cpp
add_executable(${ProjectName} ${ProjectName}/main.cpp ${ProjectName}/OpenglContext.cpp ${ProjectName}/ShaderManager.cpp ${ProjectName}/TextureManager.cpp ${ProjectName}/VertexArrayObject.cpp ${ProjectName}/VertexBufferObject.cpp ${ProjectName}/InputHandler.cpp ${ProjectName}/InputHandler.hpp
#headers
${ProjectName}/baseException.hpp ${ProjectName}/init_error.hpp ${ProjectName}/OpenglContext.hpp ${ProjectName}/ShaderManager.hpp ${ProjectName}/TextureManager.hpp ${ProjectName}/VertexArrayObject.hpp ${ProjectName}/VertexBufferObject.hpp)  

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
target_link_libraries(${ProjectName} glfw)

add_subdirectory(vendor/glad)
target_link_libraries(${ProjectName} glad)

add_subdirectory(vendor/stb)
target_link_libraries(${ProjectName} stb)
#add_library(${ProjectName} ${ProjectName}/baseException.hpp)