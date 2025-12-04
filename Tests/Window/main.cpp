#include <string>
#include "Prettiest/prettiest.h"

#include "Kandinsky/Window.h"

int main() {

	log( "Running test 'KSKY_TEST_Window'..." );

	KSKY::Window Window = KSKY::Window();
	Window.title( "Kandinsky Window Test" );

	int frame = 0;
	while ( !Window.flags.exit ) {

		frame++;

		Window.clear();
		Window.draw();

		if ( frame == 50 ) Window.size( 500, 250 );
		if ( frame == 100 ) Window.maximized( true );
		if ( frame == 150 ) Window.maximized( false );
		if ( frame == 200 ) Window.minimized( true );
		if ( frame == 250 ) Window.minimized( false );
		if ( frame == 300 ) Window.exit();

	}

	return 0;

}