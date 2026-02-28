#pragma once

#include <raylib.h>
#include <string>

namespace Core {

struct WindowSpecification
{
    std::string title {""};
    int width { 1280 };
    int height { 720 };

    // 480p
    int minWidth { 640 };
    int minHeight { 360 };
    // 4k
    int maxWidth { 3840 };
    int maxHeight { 2160 };

    float opacity { 1.0f };

    bool isResizeable { true };

    // TODO: Toggleable VSync in Raylib
    // bool vSync { true };
    
    int maxFPS { 10000 };
    // Image icon {};
};

class Window
{
private:
    WindowSpecification m_specification;
    void* m_handle = nullptr; // Only to ensure no double-free.
public:
    Window(const WindowSpecification& specification = WindowSpecification());
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void Create();
    void Destroy();

    bool ShouldClose() const;
};

}
