#include <string>
#include <bitset>
#include <functional>

#include "GLFW/glfw3.h"

namespace KSKY {

	typedef struct { int width, height; } WindowSize;
	typedef struct { int x, y; } WindowPosition;

	class Window {

		enum Events {
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

			Window() = default;

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
			void on( unsigned int, std::function<void(T)> );

		private:

			GLFWwindow* ptr;

			struct {
				bool exit;
				bool error;
				bool running;
				bool minimized;
			} flags;
			
	};

}