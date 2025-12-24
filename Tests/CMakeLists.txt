cmake_minimum_required( VERSION 3.30 )
project( Kandinsky.tests )

list(
	APPEND
	KSKY_TESTS
	Window
)

list( LENGTH KSKY_TESTS KSKY_TEST_COUNT )
if ( ${KSKY_TEST_COUNT} GREATER 0 )

	foreach( TEST ${KSKY_TESTS} )
		add_executable( ${TEST}.test ${TEST}.test.cpp )
		target_link_libraries( ${TEST}.test Kandinsky.library Prettiest )
	endforeach()

endif()