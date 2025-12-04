#include "Kandinsky/Window.h"

namespace KSKY {

	Window::Window() {

		log( "Creating window..." );

		glfwInit();

		ptr = glfwCreateWindow( 500, 500, "Untitled Application", NULL, NULL );
		
		if (ptr == NULL) {
			error( "Could not create window. Double-check that your computer is on." );
			flags.error = true;
			return;
		}

		flags.exit = false;
		flags.error = false;
		flags.minimized = false;

		glfwMakeContextCurrent( ptr );
		gladLoadGL( glfwGetProcAddress );

		glViewport( 0, 0, 500, 500 );
	}

	void Window::draw() {

		glfwSwapBuffers( ptr );
		glfwPollEvents();

		flags.exit = glfwWindowShouldClose( ptr );

	}

	void Window::clear() {

		glClear( GL_COLOR_BUFFER_BIT );

	}

	void Window::exit() {

		glfwDestroyWindow( ptr );

	}

	void Window::size( int w, int h ) {

		glfwSetWindowSize( ptr, w, h );
		glViewport( 0, 0, w, h );

	}
	WindowSize Window::size() {
		int w, h;
		glfwGetFramebufferSize( ptr, &w, &h );

		return WindowSize( w, h );
	}

	void Window::maximized( bool opt ) {

		if ( opt == flags.minimized ) return;
		
		if ( opt == true ) glfwMaximizeWindow( ptr );
		else glfwIconifyWindow( ptr );

		WindowSize SIZE = size();
		glViewport( 0, 0, SIZE.width, SIZE.height );

	}

}