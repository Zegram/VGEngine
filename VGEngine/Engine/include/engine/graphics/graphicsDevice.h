
#pragma once

#include "engine/graphics/shader.h"
#include "engine/graphics/vertexBuffer.h"
#include "engine/graphics/indexBuffer.h"

namespace vg
{

	/**
	Used for drawing with given shaders and data
	*/
	class GraphicsDevice
	{
	public:

		/**
		Draws arrays with the help of given shader and vertexBuffer
		@param shader Shader used for the draw
		@param vertices Vertexbuffer which vertices are used for the draw
		*/
		static void draw(Shader* shader, VertexBuffer* vertices);

		/**
		<description>
		@param shader <description>
		@param vertices <description>
		@param indices <description>
		@param x <description>
		@param y <description>
		@param rotation <description>
		@param layer <description>
		*/
        static void draw(Shader* shader, VertexBuffer* vertices, IndexBuffer* indices,
			float x = 0.0f, float y = 0.0f, float rotation = 0.0f, uint layer = 0);
	private:
	};
}
