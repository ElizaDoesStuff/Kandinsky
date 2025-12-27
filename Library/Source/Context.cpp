#include <Kandinsky/Context.h>

namespace KSKY {

	Context::Context() {

		this->__flags__[ KSKY::Context::Flag::ERROR ] = false;

		glfwInit();

	}

	void Context::bind( KSKY::Object* object ) {

		if ( object == nullptr ) {
			this->__throw__( "Kandinsky error -- Object does not exist.\nFrankly, we're not sure why you're binding a generic Object in the first place." );
			return;
		}

		object->__bind__( this );

	}
	void Context::bind( KSKY::Window* window ) {

		if ( window == nullptr ) {
			this->__throw__( "Window does not exist.\nHonestly, we don't know what you expected us to do with a null pointer." );
			return;
		}

		window->__bind__( this );
		this->__window__ = window;

	}

	void Context::detach( KSKY::Object* object ) {

		object->__detach__();

	}

	void Context::detach( KSKY::Window* window ) {

		if ( window == nullptr ) {
			this->__throw__( "Window does not exist.\nHonestly, we don't know what you expected us to do with a null pointer." );
			return;
		}

		if ( window != this->__window__ ) {
			this->__throw__( "That window is not attached to this context.\nWe *could* detach it from its parent context, but it's fun to watch you flounder." );
			return;
		}

		window->__detach__();
		this->__window__ = nullptr;

	}

	void Context::render() {

		glfwPollEvents();

		glClear( GL_COLOR_BUFFER_BIT );

		glfwSwapBuffers( this->__window__->__internal__ );

		this->__window__->__flags__[ KSKY::Window::Flag::OPEN ] = !glfwWindowShouldClose( this->__window__->__internal__ );

	}

	bool Context::flag( KSKY::Context::Flag flag ) const {

		return __flags__.at(flag);

	}

	std::string Context::message() const {

		return this->__message__;

	}

	void Context::__throw__( std::string error ) {

		this->__flags__[ KSKY::Context::Flag::ERROR ] = true;
		this->__message__ = error;

	}

}