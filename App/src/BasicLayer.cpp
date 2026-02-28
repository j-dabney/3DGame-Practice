#include "BasicLayer.h"

#include <raylib.h>

BasicLayer::BasicLayer()
{
    SetExitKey(KEY_ESCAPE);
}

BasicLayer::~BasicLayer()
{
}

void BasicLayer::OnUpdate()
{
}

void BasicLayer::OnRender()
{
    ClearBackground(DARKGRAY);

    DrawText("(c++) 3DGame by Justin Dabney", GetScreenWidth() - 200, GetScreenHeight() - 20, 10, GRAY);
}
