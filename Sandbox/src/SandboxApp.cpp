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
		HM_INFO("ExampleLayer::Update");
	}

	void OnEvent(HazmatEngine::Event& event) override
	{
		HM_TRACE("{0}", event);
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