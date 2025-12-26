#ifndef KSKY_WINDOW_H // Header
#define KSKY_WINDOW_H // Guard

#include <Kandinsky/Context.h>
#include <Kandinsky/Object.h>

namespace KSKY {

	class Context;
	class Object;

	class Window : Object {
		public:

			Window() = default;

			void __bind__( KSKY::Context* );
			void __detach__();
	};

}

#endif