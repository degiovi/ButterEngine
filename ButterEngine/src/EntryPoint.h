#pragma once

#ifdef BTR_PLATFORM_WINDOWS

extern Butter::Application* Butter::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Butter::CreateApplication();
	app->Run();
	delete app;
}

#endif