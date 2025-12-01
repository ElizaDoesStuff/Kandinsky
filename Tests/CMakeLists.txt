cmake_minimum_required( VERSION 3.30 )
project( Kandinsky.TESTS )

list(
	APPEND KSKY_TEST_DIRS
	Window
)

foreach( TEST IN LISTS KSKY_TEST_DIRS )

	add_executable( KSKY_TEST_${TEST} ${PROJECT_SOURCE_DIR}/${TEST}/main.cpp )
	target_link_libraries( KSKY_TEST_${TEST} Kandinsky.LIB Prettiest )

endforeach()