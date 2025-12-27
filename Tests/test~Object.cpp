#include <Prettiest/Prettiest.h>

#include <Kandinsky/Object.h>
#include <Kandinsky/Context.h>

#define TEST "test~Object"

int main() {

	log( "Running test '" TEST "'" );

	KSKY::Context Context;
	KSKY::Object TestObject;

	Context.bind( &TestObject );
	if ( Context.flag( KSKY::Context::Flag::ERROR ) ) error( Context.message() );
	else log( "Test object has been bound!" );

	// Note: raw objects can't really be detached because they are never
	// really bound anywhere on the context, but this is still here
	// as a test of the default detach function
	Context.detach( &TestObject );
	if ( Context.flag( KSKY::Context::Flag::ERROR ) ) error( Context.message() );
	else log( "Test object has been detached!" );

	log( "Completed test '" TEST "'" );

}