#pragma once

#include "GameScene.h"
#include "Window.h"
#include "OneScene.h"

using namespace Engine;

int main()
{
    Window* window = new Window(1100, 700, "Game", false);

    window->setGameScene(new OneScene(window));

    window->launch();

	return 0;
}