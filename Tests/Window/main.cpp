#include "Prettiest/prettiest.h"
#include "Kandinsky/Window.h"

int main() {

	log( "Running test 'KSKY_TEST_Window'..." );

	KSKY::Window Window = KSKY::Window();
	// Window.title( "Kandinsky Window Test" );
	// Window.maximized( true );

	while ( !Window.flags.exit ) {
		Window.clear();
		Window.draw();
	}

	Window.exit();

	return 0;

}