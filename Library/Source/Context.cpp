#include <Kandinsky/Context.h>

namespace KSKY {

	void Context::bind( KSKY::Object* object ) {
		object->__bind__( this );
	}

	void Context::detach( KSKY::Object* object ) {
		object->__detach__();
	}

}