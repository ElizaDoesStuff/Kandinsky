#include <Prettiest/prettiest.h>
#include <Kandinsky/Window.h>

int main() {

	log( "Running test: Window.test!" );

	KSKY::Window Window;

	if ( &Window == nullptr ) { error( "Failed to create window." ); return 1; }

	return 0;

}