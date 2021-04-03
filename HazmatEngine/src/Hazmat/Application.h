#pragma once

#include "Core.h"

#include "Window.h"
#include "Hazmat/LayerStack.h"
#include "Hazmat/Events/Event.h"
#include "Hazmat/Events/ApplicationEvent.h"

#include "Hazmat/ImGui/ImGuiLayer.h"

#include "Hazmat/Renderer/Shader.h"
#include "Hazmat/Renderer/Buffer.h"

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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}