#include <HazmatEngine.h>

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
		PushOverlay(new HazmatEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

HazmatEngine::Application* HazmatEngine::CreateApplication()
{
	return new Sandbox();
}