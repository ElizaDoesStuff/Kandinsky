#include <Kandinsky/Context.h>

namespace KSKY {

	void Context::bind( KSKY::Object* object ) {
		object->__bind__( this );
	}

}