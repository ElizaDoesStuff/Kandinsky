// Kandinsky includes
#include <Kandinsky/Window.h>

namespace KSKY {

	Window::Window() {

		// Public properties
		this->bound = false;

		// Internal properties
		this->__pointer__ = nullptr;

		// Private properties
		this->context = nullptr;
	};

	void Window::__bind__( KSKY::Context* context ) {

		this->context = context;
		this->__pointer__ = glfwCreateWindow( 640, 480, this->__cache__.title.c_str(), NULL, NULL );
		if ( !this->__pointer__ ) {
			this->context->__raise__(
				"[ERROR]: Kandinsky internal error: could not create GLFW window object."
			);
			this->context = nullptr;
			return;
		}
		this->bound = true;

	}

	KSKY::Window& Window::title( std::string title ) {

		if ( ! this->bound ) this->__cache__.title = title;
		else glfwSetWindowTitle( this->__pointer__, title.c_str() );

		return *this;

	}

}