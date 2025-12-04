cmake_minimum_required( VERSION 3.30 )
project( Kandinsky.LIB )

add_library( 
	${PROJECT_NAME}
	STATIC
	Source/Window.cpp
)

target_link_libraries(
	${PROJECT_NAME}
	glfw
	Prettiest
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	Include
)