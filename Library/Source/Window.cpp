// Kandinsky includes
#include <Kandinsky/Window.h>

namespace KSKY {

	Window::Window() {};

	void Window::__bind__( KSKY::Context* context ) {

		this->context = context;
		this->__pointer__ = glfwCreateWindow( 640, 480, "New Kandinsky window!", NULL, NULL );

	}

}