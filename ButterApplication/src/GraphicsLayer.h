#pragma once

#include "Butter.h"

class GraphicsLayer : public Butter::Layer
{

public:
	
	GraphicsLayer();
	virtual ~GraphicsLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate() override;
	void OnEvent(Butter::Event & e) override;

private:

	Butter::Ref<Butter::Shader> shader_compute;
	Butter::Ref<Butter::Shader> shader_fullscreenTri;
	Butter::Ref<Butter::Texture> tex;
	Butter::Camera camera;

	glm::vec2 resolution = glm::vec2(512, 512);

	glm::vec3 lightDir = glm::vec3(-1.0f, -0.5f, 0.0f);
	float index = 0.0f;
	float increment = 0.01f;

	float yOffset = 0.0f;

	bool OnKeyPressed(Butter::KeyPressedEvent & e);
	bool OnMouseMoved(Butter::MouseMovedEvent & e);

};