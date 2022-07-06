#pragma once

#include "GameObject.h"
#include "PhysicalFunction.h"
#include "Bullet.h"
#include "Damage.h"

#include <math.h>

#include <SFML/Graphics.hpp>

using namespace Engine;

class Player : public GameObject
{
private:
	int frequency = 200, timer = 2000;

public:
	Player(GameScene* scene, Vector2i size);

	void run(int time) override;
};