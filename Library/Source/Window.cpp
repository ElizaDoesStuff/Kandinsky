#include "Prettiest/prettiest.h"
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

	}

	void Window::draw() {

		glfwSwapBuffers(ptr);
		glfwPollEvents();

		flags.exit = glfwWindowShouldClose(ptr);

	}

	void Window::clear() {}

	void Window::exit() {

		glfwDestroyWindow(ptr);

	}

}