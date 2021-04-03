#pragma once

#include "Hazmat/Layer.h"

#include "Hazmat/Events/ApplicationEvent.h"
#include "Hazmat/Events/KeyEvent.h"
#include "Hazmat/Events/MouseEvent.h"

namespace HazmatEngine
{
	class HAZMAT_ENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}