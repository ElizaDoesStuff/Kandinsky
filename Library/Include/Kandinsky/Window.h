#include <string>
#include <bitset>
#include <functional>

#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include "Prettiest/prettiest.h"

namespace KSKY {

	typedef struct { int width, height; } WindowSize;
	typedef struct { int x, y; } WindowPosition;

	class Window {

		enum class Event {
			WindowResize,
			WindowMove,

			WindowFocus,
			WindowUnfocus,

			WindowMinimize,
			WindowMaximize,

			KeyDown,
			KeyUp,
			KeyRepeat,

			MouseDown,
			MouseUp,
			MouseMove,
		};

		public:

			Window();

			void draw();
			void clear();
			void exit();

			void title( std::string );
			std::string title();

			void size( int, int );
			WindowSize size();

			void position( int, int );
			WindowPosition position();

			void maximized( bool );
			bool maximized();

			void focused( bool );
			bool focused();

			template<typename T>
			void on( Event, std::function<void(T)> );

			struct {
				bool exit;
				bool error;
				bool minimized;
			} flags;

		private:

			GLFWwindow* ptr;
			
	};

}