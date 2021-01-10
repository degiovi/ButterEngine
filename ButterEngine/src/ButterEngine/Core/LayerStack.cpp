#include "btrpch.h"
#include "ButterEngine/Core/LayerStack.h"

namespace Butter
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer * layer : layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer * layer)
	{
		// Layers get pushed into the first half of the list (on top)
		layers.emplace(layers.begin() + layerInsertIndex, layer);
		layerInsertIndex++;
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
			layer->OnDetach();
			layers.erase(it);
			layerInsertIndex--;
		}
	}


	void LayerStack::PopOverlay(Layer * overlay)
	{
		auto it = std::find(layers.begin(), layers.end(), overlay);

		if (it != layers.end())
		{
			overlay->OnDetach();
			layers.erase(it);
		}
	}
}