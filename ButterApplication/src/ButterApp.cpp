#include "Butter.h"

#include "ButterEngine/Core/EntryPoint.h"
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
	
		const char * path = "src/assets/meshes/cube.obj";
		/*
		std::string txt;
		std::vector<std::string> lines;

		Butter::FileUtil fileUtil;
		fileUtil.OpenFile(&path, &txt);
		*/

		Butter::ObjLoader objLoader;

		Butter::ObjData objData;

		objLoader.Load(path, &objData);

		if (objData.vertices.size() > 0)
		{
			objData.vertices[0].Print();

		}
		else
		{
			BTR_INFO("Didn't find any vertex data in the .obj");
		}

		


		

		//fileUtil.OpenFile(&path, &lines);
		
		/*
		for (int i = 0; i < lines.size(); i++)
		{
			BTR_INFO(lines[i]);
		}
		*/

		/*
		std::fstream file;

		file.open("src/assets/templates/example.txt");

		if (file.is_open())
		{
			std::string currLine;

			for (int lines = 0; std::getline(file, currLine); lines++)
			{
				BTR_INFO(currLine);
			}


		}
		else
		{
			BTR_INFO("File was not opened.");
		}
		*/
		PushLayer(new GraphicsLayer());


		
		

		//PushOverlay(new Butter::ImGuiLayer());
		
		//std::shared_ptr<Butter::Entity> e = entityManager->CreateEntity();
		//entityManager->AddComponent(e, std::make_shared<Butter::Transform>(glm::vec3{ 0.0f,0.0f,0.0f }, glm::vec3{ 0.0f,0.0f,0.0f }, glm::vec3{ 1.0f,1.0f,1.0f }));

		/*
		Butter::Vector2 v2 = { 5.0f, 6.0f };
		Butter::Vector3 v3 = { 80.5f, 92.1f, 77.8f };
		Butter::Vector4 v4 = { 11.9f, 11.2f, 5.0f, 72.0f };

		Butter::Vector4 secondV4 = { 5.0f, 6.0f, 7.0f, 8.0f };
		Butter::List<int> aList = { 1, 2, 3 };
		//v2.Print();
		//v3.Print();
		//v4.Print();

		Butter::Mat2D<Butter::Vector4> matrix = Butter::Mat2D<Butter::Vector4>(10, 10);
		matrix.Set(5, 5, { 8.0f, 9.0f, 10.0f, 11.0f });
		matrix.Get(5, 5)->Print();

		matrix.Print();
		*/
		

	}

	~ButterApp()
	{

	}


};


Butter::Application* Butter::CreateApplication()
{
	return new ButterApp();
}