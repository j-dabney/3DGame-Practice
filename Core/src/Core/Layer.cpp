#include "Layer.h"

#include "Application.h"

namespace Core {

void Layer::QueueTransition(std::unique_ptr<Layer> toLayer)
{
    // TODO: Fix this
    auto& layerStack = Application::Get().m_layerStack;
    for (auto& layer : layerStack)
    {
        if (layer.get() == this)
        {
            layer = std::move(toLayer);
            return;
        }
    }
}

}
