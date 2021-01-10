#pragma once

#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Core/Layer.h"

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

		std::vector<Layer*>::reverse_iterator rbegin() { return layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return layers.begin(); }
		std::vector<Layer*>::const_iterator end() const { return layers.end(); }
		
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return layers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return layers.rend(); }

		
		




	private:

		std::vector<Layer*> layers;
		unsigned int layerInsertIndex = 0;
		//std::vector<Layer*>::iterator layerPos;
	};
}