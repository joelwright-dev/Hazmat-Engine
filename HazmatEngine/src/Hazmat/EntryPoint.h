#pragma once

#ifdef HM_PLATFORM_WINDOWS

extern HazmatEngine::Application* HazmatEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = HazmatEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif