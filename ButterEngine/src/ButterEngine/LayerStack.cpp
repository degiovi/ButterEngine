#include "btrpch.h"
#include "ButterEngine/LayerStack.h"

namespace Butter
{
	LayerStack::LayerStack()
	{
		// Initialize layerIterator at the beginning of the layers stack
		layerPos = layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer * layer : layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer * layer)
	{
		// Layers get pushed into the first half of the list (on top)
		layerPos = layers.emplace(layerPos, layer);

		// After pushing a layer on to the stack, we save back the position
	}

	void LayerStack::PushOverlay(Layer * overlay)
	{
		// Overlays are always added to the very back (to be rendered last, on top of everything)
		layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer * layer)
	{
		auto it = std::find(layers.begin(), layers.end(), layer);
		
		if (it != layers.end())
		{
			layers.erase(it);
			layerPos--;
		}
	}


	void LayerStack::PopOverlay(Layer * overlay)
	{
		auto it = std::find(layers.begin(), layers.end(), overlay);

		if (it != layers.end())
			layers.erase(it);
	}
}