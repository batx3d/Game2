#pragma once

#include "GameScene.h"
#include "Player.h"
#include "Vector2i.h"
#include "Window.h"

using namespace Engine;

class FirstLevel
{
public:
	GameScene* scene;

	FirstLevel(Window* window);

	GameScene* getGameScene();
};