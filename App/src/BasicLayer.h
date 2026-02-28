#pragma once

#include "Core/Layer.h"

#include <raylib.h>

class BasicLayer : public Core::Layer
{
public:
    BasicLayer();
    virtual ~BasicLayer() override;

    virtual void OnUpdate() override;
    virtual void OnRender() override;
};
