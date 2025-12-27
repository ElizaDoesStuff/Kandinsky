cmake_minimum_required( VERSION 3.30 )
project( Kandinsky.library )

add_library(
	${PROJECT_NAME}
	STATIC
	Source/Context.cpp
	Source/Object.cpp
	Source/Window.cpp
)

target_link_libraries( ${PROJECT_NAME} PUBLIC glad glfw )

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${PROJECT_SOURCE_DIR}/Include
)