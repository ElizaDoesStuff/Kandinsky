cmake_minimum_required( VERSION 3.30 )
project( Kandinsky.TOP )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)


if( STREQUAL ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} )
	set( KSKY_STANDALONE ON )
else()
	set( KSKY_STANDALONE OFF )
endif()

add_subdirectory( Dependencies )
add_subdirectory( Library )

if (NOT KSKY_STANDALONE)
	add_subdirectory( Tests )
endif()