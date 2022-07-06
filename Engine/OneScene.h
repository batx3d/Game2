#pragma once

#include "GameScene.h"

using namespace Engine;

class OneScene : public GameScene
{
public:
	OneScene(Window* window);

	void run(int time) override;
};