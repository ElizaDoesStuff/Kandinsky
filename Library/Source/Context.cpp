// Kandinsky includes
#include <Kandinsky/Context.h>

namespace KSKY {

	Context::Context() {

		glfwInit();

	};

	void Context::bind( KSKY::Window* window ) {

		window->__bind__( this );
		this->window = window;

		this->ready = true;

	}

	void Context::render() {

		if ( !this->window ) { 
			this->raise( 
				"[ERROR]: Could not execute Context.render(); Window not bound.\n"
				"Please bind a window before attempting to render.\n" 
			);
			this->ready = false;
			return;
		}

		glfwPollEvents();

		this->ready = !glfwWindowShouldClose( this->window->__pointer__ );

	}

	void Context::raise( std::string message ) {

		this->error = true;
		this->message = message;

	}

}