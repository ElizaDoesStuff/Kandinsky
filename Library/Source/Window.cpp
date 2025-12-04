#include "Kandinsky/Window.h"

namespace KSKY {

	Window::Window() {

		glfwInit();

		ptr = glfwCreateWindow( 500, 500, "Untitled Application", NULL, NULL );

		log( "Created window!" );
		
		if ( ptr == NULL ) {
			error( "Could not create window. Double-check that your computer is on." );
			flags.error = true;
			return;
		}

		flags.exit = false;
		flags.error = false;

		glfwMakeContextCurrent( ptr );
		gladLoadGL( glfwGetProcAddress );

		glViewport( 0, 0, 500, 500 );
	}
	Window::~Window() {

		if ( flags.exit ) return;
		glfwDestroyWindow( ptr );

	}

	void Window::draw() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		glfwSwapBuffers( ptr );
		glfwPollEvents();

		flags.exit = glfwWindowShouldClose( ptr );

	}

	void Window::clear() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		glClear( GL_COLOR_BUFFER_BIT );

	}

	void Window::exit() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		flags.exit = true;
		glfwDestroyWindow( ptr );

		log( "Exited window." );

	}

	void Window::title( std::string t ) {

		log( "Set title to: " + t );

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		glfwSetWindowTitle( ptr, t.c_str() );

	}
	std::string Window::title() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return "";
		}

		std::string t( glfwGetWindowTitle( ptr ) );
		return t;

	}

	void Window::size( int w, int h ) {

		log( "Set window dimensions to: " + std::to_string(w) + "x" + std::to_string(h) );

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		glfwSetWindowSize( ptr, w, h );
		glViewport( 0, 0, w, h );

	}
	WindowSize Window::size() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return { 0, 0 };
		}

		int w, h;
		glfwGetFramebufferSize( ptr, &w, &h );

		return WindowSize( w, h );
	}

	void Window::maximized( bool m ) {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		if ( m == maximized() ) return;
		
		log( "Set maximized status to: " + std::to_string( m ) );

		if ( m == true ) glfwMaximizeWindow( ptr );
		else { restore(); };

		WindowSize SIZE = size();
		glViewport( 0, 0, SIZE.width, SIZE.height );

	}
	bool Window::maximized() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return false;
		}

		return ( glfwGetWindowAttrib( ptr, GLFW_MAXIMIZED ) == GLFW_TRUE );

	}

	void Window::minimized( bool m ) {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		if ( m == minimized() ) return;

		log( "Set minimized status to: " + std::to_string( m ) );
		
		if ( m ) glfwIconifyWindow( ptr );
		else { restore(); }

		WindowSize SIZE = size();
		glViewport( 0, 0, SIZE.width, SIZE.height );

	}
	bool Window::minimized() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return false;
		}

		return ( glfwGetWindowAttrib( ptr, GLFW_ICONIFIED ) == GLFW_TRUE );

	}

	void Window::restore() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		glfwRestoreWindow( ptr );

	}

	void Window::focused( bool m ) {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return;
		}

		if ( m == focused() ) return;
		
		if ( m == true ) glfwFocusWindow( ptr );
		else warn("Sorry, window unfocusing is not supported under GLFW.");

	}
	bool Window::focused() {

		if ( flags.exit ) {
			warn("Window has already exited; cannot be accessed.");
			return false;
		}

		return ( glfwGetWindowAttrib( ptr, GLFW_FOCUSED ) == GLFW_TRUE );

	}

}