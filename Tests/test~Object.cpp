#include <Prettiest/prettiest.h>

#include <Kandinsky/Object.h>
#include <Kandinsky/Context.h>

#define TEST "test~Object"

int main() {

	log( "Running test '" TEST "'" );

	KSKY::Context Context;
	KSKY::Object TestObject;

	Context.bind( &TestObject );
	if ( !TestObject.bound ) error( "Test object was not bound." );
	else log( "Test object has been bound!" );

	log( "Completed test '" TEST "'" );

}