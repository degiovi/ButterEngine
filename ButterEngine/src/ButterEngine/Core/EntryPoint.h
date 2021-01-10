#pragma once
#include "ButterEngine/Core/Core.h"

#ifdef BTR_PLATFORM_WINDOWS

extern Butter::Application* Butter::CreateApplication();

int main(int argc, char** argv)
{
	Butter::Log::Init();

	auto app = Butter::CreateApplication();
	app->Run();
	delete app;
}

#endif

