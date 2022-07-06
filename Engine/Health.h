#pragma once

#include "Damage.h"

class Health
{
private:
	int health;

public:
	Health(int health);
	void setDamage(Damage damage);
	int getHealth();
};