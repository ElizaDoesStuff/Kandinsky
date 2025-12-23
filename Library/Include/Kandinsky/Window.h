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
			// bound flag -- denotes whether this window has been bound to a context yet
			bool bound = false;
			//
			// .------------------------.
			// |     Public Methods     |
			// '------------------------'
			//
			// Default constructor
			Window();
			//
			// "bind" function -- an internal function that is automatically called when the window is bound
			void __bind__( KSKY::Context* );
			//
			// Getter/Setter functions -- Modify or retrieve window attributes
			KSKY::Window& title( std::string );
			std::string title();
			//
//		internal:
			//
			// .-----------------------------.
			// |     Internal Properties     |
			// '-----------------------------'
			//
			// window pointer -- a pointer to the internal glfw window object that the instance represents
			GLFWwindow* __pointer__ = nullptr;
			// 
			// cache -- a struct containing cached settings to be applied once the window is bound
			struct Cache {

				std::string title;

			} __cache__;
			//
		private:
			//
			// .----------------------------.
			// |     Private Properties     |
			// '----------------------------'
			//
			// context pointer -- a pointer to the parent context that this window is bound to, if any
			KSKY::Context* context = nullptr;
	};

}

// Header Guard
#endif