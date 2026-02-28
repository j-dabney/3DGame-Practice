#include "Window.h"
#include <cassert>
#include <iostream>
#include <raylib.h>

namespace Core {

Window::Window(const WindowSpecification& specification) : m_specification{ specification }
{
}

Window::~Window()
{
    Destroy();
}

void Window::Create()
{
    InitWindow(m_specification.width, m_specification.height, m_specification.title.c_str());

    InitAudioDevice();

    if (!IsWindowReady())
    {
        std::cerr << "Failed to create window!\n";
        assert(false);
    }

    m_handle = GetWindowHandle();

    SetExitKey(KEY_NULL); // Disables Esc closing window

    // TODO: Look into this further
    SetTargetFPS(m_specification.maxFPS);

    // TODO: Add icon functionality
    // if (m_specification.icon) SetWindowIcon(m_specification.icon);

    SetWindowMinSize(m_specification.minWidth, m_specification.minHeight);
    SetWindowMaxSize(m_specification.maxWidth, m_specification.maxHeight);

    SetWindowOpacity(m_specification.opacity);
}

void Window::Destroy()
{
    if (m_handle)
    {
        CloseAudioDevice();
        CloseWindow();
        m_handle = nullptr;
    }
}

bool Window::ShouldClose() const
{
    if (WindowShouldClose()) return true;
    return false;
}

}
