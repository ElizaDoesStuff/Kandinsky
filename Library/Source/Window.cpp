#include <Kandinsky/Window.h>

namespace KSKY {

	void Window::bind( KSKY::Context* context ) {
		this->bound = true;
		this->__parent__ = context;
	}

}