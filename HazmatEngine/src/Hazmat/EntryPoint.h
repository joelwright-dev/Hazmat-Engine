#pragma once

#ifdef HM_PLATFORM_WINDOWS

extern HazmatEngine::Application* HazmatEngine::CreateApplication();

int main(int argc, char** argv)
{
	HazmatEngine::Log::Init();
	HM_CORE_WARN("Initialized Log!");
	int a = 5;
	HM_INFO("Hello! Var={0}", a);

	auto app = HazmatEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif