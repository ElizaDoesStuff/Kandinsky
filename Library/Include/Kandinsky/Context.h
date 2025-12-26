#ifndef KSKY_CONTEXT_H // Header
#define KSKY_CONTEXT_H // Guard

#include <Kandinsky/Object.h>
#include <Kandinsky/Window.h>

#include <string>

namespace KSKY {

	class Object;
	class Window;

	class Context {
		public:
			const struct Flags {
				bool error = false;
			} flags;

			KSKY::Window* window = nullptr;

			Context() = default;

			void bind( KSKY::Object* );

			void detach( KSKY::Object* );

			void __throw__( std::string );
	};

}

#endif