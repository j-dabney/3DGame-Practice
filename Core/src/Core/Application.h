#pragma once

#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "Layer.h"
#include "Window.h"

#include "raylib.h"

namespace Core {

struct ApplicationSpecification
{
    std::string name = "Application";
    WindowSpecification windowSpec {};
};

class Application
{
private:
    ApplicationSpecification m_specification {};
    std::shared_ptr<Window> m_window {};
    bool m_running { false };

    std::vector<std::unique_ptr<Layer>> m_layerStack {};

    friend class Layer;

public:
    Application(const ApplicationSpecification& specification = ApplicationSpecification());
    ~Application();

    void Run();
    void Stop();

    template<typename TLayer>
    requires(std::is_base_of_v<Layer, TLayer>)
    void PushLayer()
    {
        m_layerStack.push_back(std::make_unique<TLayer>());
    }

    template<typename TLayer>
    requires(std::is_base_of_v<Layer, TLayer>)
    TLayer* GetLayer()
    {
        for (const auto& layer : m_layerStack)
        {
            if (auto casted = dynamic_cast<TLayer*>(layer.get()))
                return casted;
        }
        return nullptr;
    }

    static Application& Get();
};

}
