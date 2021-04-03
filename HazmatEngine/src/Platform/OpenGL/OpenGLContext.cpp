#include "hmpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace HazmatEngine {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle)
	{
		HM_CORE_ASSERT(windowHandle, "Window Handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HM_CORE_ASSERT(status, "Failed to initialize Glad!");

		HM_CORE_INFO("OpenGL Info:");
		HM_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		HM_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		HM_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_windowHandle);
	}
}