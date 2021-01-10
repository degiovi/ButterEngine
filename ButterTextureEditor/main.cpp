#include "Butter.h"
#include "ButterEngine/Core/EntryPoint.h"
#include "EditorLayer.h"

class ButterTextureEditor : public Butter::Application
{

public:

	ButterTextureEditor()
	{
		
		PushOverlay(new EditorLayer);


	}

	~ButterTextureEditor()
	{

	}


};


Butter::Application* Butter::CreateApplication()
{
	return new ButterTextureEditor();
}