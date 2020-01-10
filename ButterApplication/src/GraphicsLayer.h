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

};