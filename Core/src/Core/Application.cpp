#include "Application.h"
#include "Layer.h"

#include <cassert>
#include <cstdarg>
#include <iostream>
#include <raylib.h>

namespace Core {

static Application* s_application { nullptr };

static void CustomTraceLog(int msgType, const char* description, va_list args)
{
    switch (msgType)
    {
        case LOG_INFO: std::cout << "[Raylib INFO]: "; break;
        case LOG_ERROR: std::cerr << "[Raylib ERROR]: "; break;
        case LOG_WARNING: std::cout << "[Raylib WARN]: "; break;
        case LOG_DEBUG: std::cout << "[Raylib DEBUG]: "; break;
        default: break;
    }
    std::vprintf(description, args);
    std::cout << '\n';
}

Application::Application(const ApplicationSpecification& specification) : m_specification{ specification }
{
    s_application = this;

    SetTraceLogCallback(CustomTraceLog);

    if (m_specification.windowSpec.title.empty())
        m_specification.windowSpec.title = m_specification.name;

    m_window = std::make_shared<Window>(m_specification.windowSpec);
    m_window->Create();
}

Application::~Application()
{
    m_layerStack.clear();

    m_window->Destroy();

    s_application = nullptr;
}

void Application::Run()
{
    m_running = true;

    while (m_running)
    {
        if (m_window->ShouldClose())
        {
            Stop();
            break;
        }

        for (const std::unique_ptr<Layer>& layer : m_layerStack)
            layer->OnUpdate();

        BeginDrawing();
        for (const std::unique_ptr<Layer>& layer : m_layerStack)
            layer->OnRender();
        EndDrawing();
    }
}

void Application::Stop()
{
    m_running = false;
}

Application& Application::Get()
{
    assert(s_application);
    return *s_application;
}

}
