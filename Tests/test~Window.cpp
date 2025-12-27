#include <Prettiest/Prettiest.h>

#include <Kandinsky/Context.h>
#include <Kandinsky/Window.h>

#define TEST "test~Window"

int main() {

	log( "Running test '" TEST "'" );

	KSKY::Context Context;
	KSKY::Window Window;
	
	Context.bind( &Window );
	if ( Context.flag( KSKY::Context::Flag::ERROR ) ) error( Context.message() );
	else log( "Window has been bound!" );

	while ( Window.flag( KSKY::Window::Flag::OPEN ) ) {
		Context.render();
	}

	log( "Completed test '" TEST "'" );

}