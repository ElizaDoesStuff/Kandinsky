// Dependencies
#include <Prettiest/prettiest.h>

// Kandinsky includes
#include <Kandinsky/Context.h>
#include <Kandinsky/Window.h>
// #include <Kandinsky/Buffer.h>
// #include <Kandinsky/Shader.h>

int main() {

	log( "Running Kandinsky Pipeline test..." );

	KSKY::Context Context;

	KSKY::Window Window;
	Context.bind( &Window );

	// KSKY::VertexBuffer VertexBuffer;
	// Context.bind( VertexBuffer, KSKY::BUFFER::ARRAY );

	// KSKY::IndexBuffer IndexBuffer;
	// Context.bind( IndexBuffer, KSKY::BUFFER::INDEX );

	// KSKY::ShaderManager ShaderManager;
	// Context.bind( ShaderManager );

	// KSKY::Shader VertexShader;
	// ShaderProgram.bind( VertexShader, KSKY::SHADER::VERTEX );

	// KSKY::Shader FragmentShader;
	// ShaderProgram.bind( FragmentShader, KSKY::SHADER::FRAGMENT );

	// ShaderManager.compile();
	
	while ( Context.valid ) Context.render();

	if ( Context.error ) error( Context.message );

}