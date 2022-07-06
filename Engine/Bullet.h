#pragma once

#include "GameObject.h"
#include "Damage.h"

using namespace Engine;

class Bullet : public GameObject
{
private:
	Damage damage;

public:
	Bullet(GameScene* scene, Vector2f positions, Vector2f speed, Damage damage);
	void run(int time) override;

	Damage getDamage();
};