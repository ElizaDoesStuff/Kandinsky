#ifndef KSKY_OBJECT_H // Header
#define KSKY_OBJECT_H // Guard

#define KSKY_WINDOW_H // Prevent this file from including Kandinsky/Window.h

#include <Kandinsky/Context.h>

namespace KSKY {

	class Context;
	class Object {
		public:
			bool bound = false;

			Object() = default;

			friend KSKY::Context;
		protected:
			virtual void __bind__( KSKY::Context* );
			virtual void __detach__();
			KSKY::Context* __parent__ = nullptr;
	};

}

#endif