#pragma once

#include "Core.h"

namespace Butter
{

	class BUTTER_API Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();

	};

	Application* CreateApplication();

}