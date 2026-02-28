#pragma once

#include <memory>

namespace Core {

class Layer
{
public:
    virtual ~Layer() = default;

    virtual void OnUpdate() {}
    virtual void OnRender() {}

    bool GetIsAcceptingInput() const { return m_isAcceptingInput; };
    void SetIsAcceptingInput(bool isAcceptingInput) { m_isAcceptingInput = isAcceptingInput; };

    template<std::derived_from<Layer> T, typename... Args>
    void TransitionTo(Args&&... args)
    {
        QueueTransition(std::move(std::make_unique<T>(std::forward<Args>(args)...)));
    }

protected:
    bool m_isAcceptingInput { true }; // For layer-stacking.

private:
    void QueueTransition(std::unique_ptr<Layer> layer);
};

}
