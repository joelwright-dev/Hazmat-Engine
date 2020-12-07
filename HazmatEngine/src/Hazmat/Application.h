#pragma once

#include "Core.h"

namespace HazmatEngine {
	class HAZMAT_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}