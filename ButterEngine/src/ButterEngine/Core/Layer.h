#pragma once

#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Events/Event.h"

namespace Butter
{
	class BUTTER_API Layer
	{

	public:
		Layer(const std::string & name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event & in_event) {}

		virtual void BeginFrame() {}
		virtual void EndFrame() {}

		inline const std::string & GetName() const { return debugName; }

	protected:

		std::string debugName;
	};
}