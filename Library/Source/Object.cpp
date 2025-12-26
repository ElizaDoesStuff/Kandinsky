#include <Kandinsky/Object.h>

namespace KSKY {

	void Object::__bind__( KSKY::Context* context ) {
		this->bound = true;
		this->__parent__ = context;
	}

	void Object::__detach__() {
		this->bound = false;
		this->__parent__ = nullptr;
	}

}