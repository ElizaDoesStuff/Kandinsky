#include <string>
#include <bitset>

#include "GLFW/glfw3.h"

namespace KSKY {

	class Window {

		typedef struct { int width, height; } Size;
		typedef struct { int x, y; } Position;

		public:

			Window() = default;
			void update();
			void exit();

			void title( std::string );
			std::string title();

			void size( int, int );
			Size size();

			void position( int, int );
			Position position();

		private:

			GLFWwindow* ptr;

			struct {
				bool exit;
				bool error;
			} flags;
			
	};

}