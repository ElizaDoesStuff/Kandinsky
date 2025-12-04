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

		public:

			Window();
			~Window();

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

			void minimized( bool );
			bool minimized();

			void restore();

			void focused( bool );
			bool focused();

			struct {
				bool exit;
				bool error;
			} flags;

		private:

			GLFWwindow* ptr;
			
	};

}