// Kandinsky includes
#include <Kandinsky/Context.h>

namespace KSKY {

	Context::Context() {

		glfwInit();

	};

	void Context::bind( KSKY::Window* window ) {

		window->__bind__( this );
		this->window = window;

	}

	void Context::render() {

		if ( this->window == nullptr ) { 
			this->__raise__( 
				"[ERROR]: Could not execute Context.render() - Window not bound.\n"
				"Please bind a window before attempting to render.\n" 
			);
			return;
		}

		glfwPollEvents();

		this->valid = !glfwWindowShouldClose( this->window->__pointer__ );

	}

	void Context::__raise__( std::string message ) {

		this->error = true;
		this->valid = false;
		this->message = message;

	}

}