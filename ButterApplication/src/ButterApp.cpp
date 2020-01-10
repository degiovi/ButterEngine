#include "Butter.h"

#include "ButterEngine/EntryPoint.h"
#include "GraphicsLayer.h"

class ExampleLayer : public Butter::Layer
{
public: 
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		BTR_INFO("ExampleLayer::Update");

	}
	
	void OnEvent(Butter::Event & event) override
	{
		//BTR_TRACE("{0}", event);
	}
};



class ButterApp : public Butter::Application
{

public:

	ButterApp()
	{
		PushLayer(new GraphicsLayer());
		PushOverlay(new Butter::ImGuiLayer());
		
		//std::shared_ptr<Butter::Entity> e = entityManager->CreateEntity();
		//entityManager->AddComponent(e, std::make_shared<Butter::Transform>(glm::vec3{ 0.0f,0.0f,0.0f }, glm::vec3{ 0.0f,0.0f,0.0f }, glm::vec3{ 1.0f,1.0f,1.0f }));


	}

	~ButterApp()
	{

	}


};


Butter::Application* Butter::CreateApplication()
{
	return new ButterApp();
}