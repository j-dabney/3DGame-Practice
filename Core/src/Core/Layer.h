#pragma once

#include <memory>

namespace Core {

/**
 * @class Layer
 * @brief Interface for Application layers
 */
class Layer
{
public:
    virtual ~Layer() = default;

    /**
     * @brief Variables to update on every frame
     */
    virtual void OnUpdate() {}

    /**
     * @brief Render on every frame
     */
    virtual void OnRender() {}

    bool GetIsAcceptingInput() const { return m_isAcceptingInput; };
    void SetIsAcceptingInput(bool isAcceptingInput) { m_isAcceptingInput = isAcceptingInput; };

    /**
     * @brief Queues a Layer to be transitioned to at end of frame
     * @tparam Args The Layer to transition to
     */
    template<std::derived_from<Layer> T, typename... Args>
    void TransitionTo(Args&&... args)
    {
        QueueTransition(std::move(std::make_unique<T>(std::forward<Args>(args)...)));
    }

protected:
    /** @brief If Layer is accepting input from user */
    bool m_isAcceptingInput { true };

private:
    /**
     * @brief Replaces a Layer with queued Layer at end of frame
     * @param layer The Layer to transition to
     */
    void QueueTransition(std::unique_ptr<Layer> layer);
};

}
