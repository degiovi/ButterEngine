#include <Butter.h>

class ButterApp : public Butter::Application
{

public:

	ButterApp()
	{

	}

	~ButterApp()
	{

	}


};


Butter::Application* Butter::CreateApplication()
{
	return new ButterApp();
}