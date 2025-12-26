#ifndef KSKY_OBJECT_H // Header
#define KSKY_OBJECT_H // Guard

#define KSKY_WINDOW_H // Do not include <Kandinsky/Window.h> (would cause unresolvable circular dependency)

#include <Kandinsky/Context.h>

namespace KSKY {

	class Context;
	class Object {
		public:
			bool bound = false;

			Object() = default;
			virtual void __bind__( KSKY::Context* );
			virtual void __detach__();
		private:
			KSKY::Context* __parent__ = nullptr;
	};

}

#endif