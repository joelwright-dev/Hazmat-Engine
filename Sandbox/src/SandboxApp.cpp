#include <HazmatEngine.h>

#include "imgui/imgui.h"

class ExampleLayer : public HazmatEngine::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (HazmatEngine::Input::IsKeyPressed(HM_KEY_TAB))
			HM_TRACE("Tab key is pressed (poll)");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello from sandbox");
		ImGui::End();
	}

	void OnEvent(HazmatEngine::Event& event) override
	{
		if (event.GetEventType() == HazmatEngine::EventType::KeyPressed)
		{
			HazmatEngine::KeyPressedEvent& e = (HazmatEngine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HM_KEY_TAB)
				HM_TRACE("Tab key is pressed (event)");
			HM_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public HazmatEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

HazmatEngine::Application* HazmatEngine::CreateApplication()
{
	return new Sandbox();
}