#pragma once

#include "Butter.h"
#include "imgui.h"

class EditorLayer : public Butter::ImGuiLayer
{
public:
	//EditorLayer();
	//virtual ~EditorLayer() = default;

	void OnUpdate() override;

private:
	bool IsOpen		= false;
	bool ShowGrid	= false;

	ImU32 GRID_COLOR	= IM_COL32(200, 200, 200, 40);
	float GRID_SIZE		= 64.0f;
};