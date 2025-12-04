cmake_minimum_required( VERSION 3.30 )
project( Kandinsky.DEP )

option( GLFW_BUILD_TESTS OFF )
option( GLFW_BUILD_EXAMPLES OFF )
option( GLFW_BUILD_DOCS OFF )

add_subdirectory( Prettiest )
add_subdirectory( GLFW )
add_subdirectory( glad )