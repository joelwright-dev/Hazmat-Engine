#pragma once

#include "Core.h"

#include "Window.h"
#include "Hazmat/LayerStack.h"
#include "Hazmat/Events/Event.h"
#include "Hazmat/Events/ApplicationEvent.h"

namespace HazmatEngine {
	class HAZMAT_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}