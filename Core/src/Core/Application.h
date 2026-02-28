#pragma once

#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "Layer.h"
#include "Window.h"

namespace Core {

/**
 * @brief Represents application settings
 */
struct ApplicationSpecification
{
    /** @brief Name of the application */
    std::string name = "Application";

    /** @brief WindowSpecification for application */
    WindowSpecification windowSpec {};
};

/**
 * @class Application
 * @brief A simpleton-styled class that represents the Application
 *
 * The Application Class provides methods for starting the Application, getting a pointer to the static instance,
 * stopping the Application, and managing the layer stack of the Application
 */
class Application
{
private:
    ApplicationSpecification m_specification {};
    std::shared_ptr<Window> m_window {};
    bool m_running { false };

    std::vector<std::unique_ptr<Layer>> m_layerStack {};

    friend class Layer;

public:
    /**
     * @brief Create new Application
     * @param specification Initialized ApplicationSpecification that controls the settings of the Application
     */
    Application(const ApplicationSpecification& specification = ApplicationSpecification());
    ~Application();

    /**
     * @brief Starts event loop of Application
     */
    void Run();

    /**
     * @brief Stops event loop and performs cleanup of Window
     */
    void Stop();

    /**
     * @brief Pushes a layer onto layer stack
     * @tparam TLayer Type of layer to push
     */
    template<typename TLayer>
    requires(std::is_base_of_v<Layer, TLayer>)
    void PushLayer()
    {
        m_layerStack.push_back(std::make_unique<TLayer>());
    }

    /**
     * @brief Get pointer to layer on layer stack
     * @tparam TLayer Type of layer to get pointer of
     * @return Returns nullptr if no layer of type TLayer on layer stack
     */
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

    /**
     * @brief Get reference to the instantiated Application
     */
    static Application& Get();
};

}
