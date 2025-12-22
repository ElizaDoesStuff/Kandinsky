// Header Guard
#ifndef KSKY_CONTEXT_HEADER
#define KSKY_CONTEXT_HEADER

// External includes
#include <glad/gl.h>
#include <GLFW/glfw3.h>

// Kandinsky includes
#include <Kandinsky/Window.h>

// Standard library includes
#include <string>

namespace KSKY {

	class Window; // Resolve circular dependency between Context and Window

	class Context {

		public:
			//
			// .---------------------------.
			// |     Public Properties     |
			// '---------------------------'
			//
			// Status flags -- flags for error handling and important context info 
			bool error = false;
			bool ready = false;
			//
			// Message -- used to store error messages, info, etc.
			std::string message = "";
			//
			// .------------------------.
			// |     Public Methods     |
			// '------------------------'
			//
			// Default Constructor
			Context();
			//
			// "bind" function -- Initializes objects and attaches them to the context
			void bind( KSKY::Window* );
			//
			// "render" function -- performs draw calls, swaps window buffers, and handles events
			void render();
			//
		private:
			//
			// .----------------------------.
			// |     Private Properties     |
			// '----------------------------'
			//
			// Bound objects -- pointers to objects that have been bound to the context
			KSKY::Window* window;
			//
			// .-------------------------.
			// |     Private Methods     |
			// '-------------------------'
			//
			// "raise" function -- sets the error flag and (once events are implemented) triggers an error event
			void raise( std::string );

	};

}

// Header Guard
#endif