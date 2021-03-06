
#pragma once

#include "engine/game/system.h"
#include "engine/graphics/vertexBuffer.h"
#include "engine/graphics/indexBuffer.h"
#include "engine/utility/vec2f.h"

namespace vg
{
	// Forward declaration
	class TransformComponent;
	namespace graphics
	{
		class Shader;
	}

	/**
	System that draws GameObjects with RenderComponents
	*/
	class RenderSystem :public System
	{
	public:
		/**
		Initializes RenderSystem
		*/
		RenderSystem();

		/**
		Draws all the GameObjects that contain a RenderComponent.
		*/
		void update(std::vector<GameObject*> *gameObjects,float deltaTime);

	private:
		/**
		Gets screen size from Game and sends new projection matrix to shader.
		*/
		void updateProjection();

		/**
		Makes a model transform matrix
		*/
		static glm::mat4 modelTransform(Vec2f position, Vec2f origin, Vec2f size, float rotation);

		/**
		Makes a model transform matrix using values from a TransformComponent
		*/
		static glm::mat4 modelTransform(TransformComponent* transform);

		/**
		Sends new uniform values to shader
		*/
		static void updateShader(graphics::Shader* shader, TransformComponent* transform);

		/**
		Calculates and sends new projection matrix to shader
		*/
		static void updateProjection(graphics::Shader* shader, bool useCamera = true);


		vg::graphics::VertexBuffer mVertexBuffer;	///< contains vertex data
		vg::graphics::IndexBuffer mIndexBuffer;		///< contains index data
	};

}