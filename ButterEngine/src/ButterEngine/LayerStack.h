#pragma once

#include "ButterEngine/Core.h"
#include "ButterEngine/Layer.h"

#include <vector>

namespace Butter
{
	// Layers are owned by the layer stack
	// Simple ownership, raw pointers

	class BUTTER_API LayerStack
	{

	public:

		LayerStack();
		~LayerStack();

		void PushLayer(Layer * layer);
		void PushOverlay(Layer * overlay);
		void PopLayer(Layer * layer);
		void PopOverlay(Layer * overlay);

		// Gives access for iterating layers outside this class
		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }

	private:

		std::vector<Layer*> layers;
		std::vector<Layer*>::iterator layerPos;
	};
}