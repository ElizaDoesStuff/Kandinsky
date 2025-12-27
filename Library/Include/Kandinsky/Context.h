#ifndef KSKY_CONTEXT_H // Header
#define KSKY_CONTEXT_H // Guard

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <Kandinsky/Window.h>
#include <Kandinsky/Object.h>

#include <string>
#include <unordered_map>

namespace KSKY {

	class Object;
	class Window;

	class Context {

		public:

			enum Flag {

				ERROR

			};

			Context();

			void bind( KSKY::Object* );
			void bind( KSKY::Window* );

			void detach( KSKY::Object* );
			void detach( KSKY::Window* );

			void render();

			bool flag( KSKY::Context::Flag ) const;
			std::string message() const;

			friend KSKY::Object;
			friend KSKY::Window;

		private:

			std::unordered_map<KSKY::Context::Flag, bool> __flags__;
			std::string __message__;

			KSKY::Window* __window__ = nullptr;

			void __throw__( std::string );

	};

}

#endif