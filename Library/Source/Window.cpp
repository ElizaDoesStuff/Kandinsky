#include <Kandinsky/Window.h>

namespace KSKY {

	Window::Window() {

		this->__flags__[ KSKY::Window::Flag::OPEN ] = false;

	}

	bool Window::flag( KSKY::Window::Flag flag ) {

		return this->__flags__[ flag ];

	}

	void Window::__bind__( KSKY::Context* context ) {

		if ( context == nullptr ) {
			std::cout << "Kandinsky error -- Context does not exist.\nWe don't even know how this happened." << std::endl;
			return;
		}

		this->__parent__ = context;

		this->__internal__ = glfwCreateWindow( this->__attributes__.width, this->__attributes__.height, this->__attributes__.title.c_str(), NULL, NULL );
		if ( this->__internal__ == nullptr ) {
			this->__parent__->__throw__( "Kandinsky error -- Failed to instantiate GLFW window.\nYeah, this one's on us." );
			return;
		}

		glfwMakeContextCurrent( this->__internal__ );
		gladLoadGL( glfwGetProcAddress );
		glViewport( 0, 0, this->__attributes__.width, this->__attributes__.height );

		this->bound = true;
		this->__flags__[ KSKY::Window::Flag::OPEN ] = true;

	}

	void Window::__detach__() {

		glfwDestroyWindow( this->__internal__ );

		this->bound = false;
		this->__parent__ = nullptr;

	}

	void Window::__sync__() {

		if ( this->__attributes__.width == 0 ) {
			this->__parent__->__throw__( "Kandinsky error -- Cannot set window width to 0.\nNot sure what you were hoping to render anyway." );
			this->__attributes__.width = this->__cache__.width;
		}

		if ( this->__attributes__.height == 0 ) {
			this->__parent__->__throw__( "Kandinsky error -- Cannot set window height to 0." );
			this->__attributes__.height = this->__cache__.height;
		}

		if ( this->__attributes__.width != this->__cache__.width || this->__attributes__.height != this->__cache__.height )
			glfwSetWindowSize( this->__internal__, this->__attributes__.width, this->__attributes__.height );

		if ( this->__attributes__.title != this->__cache__.title )
			glfwSetWindowTitle( this->__internal__, this->__attributes__.title.c_str() );

		this->__cache__ = this->__attributes__;

	}

}