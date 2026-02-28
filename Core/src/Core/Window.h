#pragma once

#include <string>

#include <raylib.h>

namespace Core {

/**
 * @brief Represents window settings
 */
struct WindowSpecification
{
    /** @brief Title of the window */
    std::string title {""};

    /** @brief Width in pixels of window */
    int width { 1280 };
    /** @brief Height in pixels of window */
    int height { 720 };

    /** @brief Minimum width in pixels of window */
    int minWidth { 640 };
    /** @brief Minimum height in pixels of window */
    int minHeight { 360 };

    /** @brief Maximum width in pixels of window */
    int maxWidth { 3840 };
    /** @brief Maximum height in pixels of window */
    int maxHeight { 2160 };

    /** @brief Transparancy of window */
    float opacity { 1.0f };

    /** @brief If window should be resizeable */
    bool isResizeable { true };

    // TODO: Toggleable VSync in Raylib
    //bool vSync { true };
    
    /** @brief Maximum FPS allowed for Window */
    int maxFPS { 10000 };

    // Image icon {};
};

/**
 * @class Window
 * @brief A class that controls creation and destruction of a Window
 *
 * The Window Class provides methods for creating and destroying a window in Raylib -- please note that Raylib only
 * allows one window instance
 */
class Window
{
private:
    WindowSpecification m_specification;
    void* m_handle = nullptr; // Only to ensure no double-free.
public:
    /**
     * @brief Create new Window
     * @param specification Initialized WindowSpecification that controls the settings of the Window
     */
    Window(const WindowSpecification& specification = WindowSpecification());
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    /**
     * @brief Initializes a Raylib window with the WindowSpecification settings
     */
    void Create();

    /**
     * @brief Uninitializes Raylib and cleans up Window
     */
    void Destroy();

    /**
     * @brief Used for event loop to see if Window sends a close event
     */
    bool ShouldClose() const;
};

}
