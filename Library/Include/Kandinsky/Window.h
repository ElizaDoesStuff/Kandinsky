// Header Guard
#ifndef KSKY_WINDOW_H
#define KSKY_WINDOW_H

// External includes
#include <glad/gl.h>
#include <GLFW/glfw3.h>

// Kandinsky includes
#include <Kandinsky/Context.h>

// Standard library includes
#include <string>

namespace KSKY {

	class Context; // Resolve circular dependency between Context and Window

	class Window {

		public:
			//
			// .---------------------------.
			// |     Public Properties     |
			// '---------------------------'
			//
			// window pointer -- a pointer to the internal glfw window object that the instance represents
			GLFWwindow* __pointer__;
			//
			// .------------------------.
			// |     Public Methods     |
			// '------------------------'
			//
			// Default constructor
			Window();
			//
			// "bind" function -- an internal function that is automatically called when the window is bound to a parent context
			void __bind__( KSKY::Context* );
			//
		private:
			//
			// .----------------------------.
			// |     Private Properties     |
			// '----------------------------'
			//
			// context pointer -- a pointer to the parent context that this window is bound to, if any
			KSKY::Context* context;

	};

}

// Header Guard
#endif