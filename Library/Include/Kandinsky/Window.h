#ifndef KSKY_WINDOW_H // Header
#define KSKY_WINDOW_H // Guard

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <Kandinsky/Context.h>
#include <Kandinsky/Object.h>

#include <string>
#include <iostream>
#include <unordered_map>

namespace KSKY {

	class Context;
	class Object;

	class Window : public Object {

		public:

			enum Flag {

				OPEN

			};

			Window();

			bool flag( KSKY::Window::Flag );

			friend KSKY::Context;

		private:

			std::unordered_map<KSKY::Window::Flag, bool> __flags__;
 
			struct Attributes {
				std::string title = "New Window";
				int width = 640;
				int height = 480;
			};

			Attributes __attributes__;
			Attributes __cache__;

			GLFWwindow* __internal__;

			void __bind__( KSKY::Context* ) override;
			void __detach__() override;
			void __sync__();
			
	};

}

#endif