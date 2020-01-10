#include "GraphicsLayer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

GraphicsLayer::GraphicsLayer()
	: Layer("GraphicsLayer")
{
}

void GraphicsLayer::OnAttach()
{

}

void GraphicsLayer::OnDetach()
{
}

void GraphicsLayer::OnUpdate()
{

	// Render
	{

		Butter::RenderCommand::SetClearColor({ 0.4f, 0.1f, 0.8f, 1 });
		Butter::RenderCommand::Clear();
	}

}

void GraphicsLayer::OnEvent(Butter::Event & e)
{
}