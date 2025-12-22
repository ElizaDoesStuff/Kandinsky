// External includes
#include <Prettiest/prettiest.h>

// Kandinsky includes
#include <Kandinsky/Context.h>
#include <Kandinsky/Window.h>


int main() {

	log( "Running test 'Window.test'..." );
	
	KSKY::Context Context;
	KSKY::Window Window;

	Context.bind( &Window );
	while ( Context.ready ) {
		Context.render();
	}

}