// External includes
#include <Prettiest/prettiest.h>

// Kandinsky includes
#include <Kandinsky/Context.h>
#include <Kandinsky/Window.h>


int main() {

	log( "Running test 'Window.test'..." );
	
	KSKY::Context Context;
	KSKY::Window Window;

	Window
		.title("Test Title 1")
		.title("Test Title 2")
		.title("Test Title 3");

	Context.bind( &Window );
	while ( Context.valid ) {
		Context.render();
	}
	if ( Context.error ) error( Context.message );

}