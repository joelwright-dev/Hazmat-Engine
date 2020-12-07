#include <HazmatEngine.h>

class Sandbox : public HazmatEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

HazmatEngine::Application* HazmatEngine::CreateApplication()
{
	return new Sandbox();
}