#include "Health.h"

Health::Health(int health) {
	if (health >= 0)
		this->health = health;
	else
		this->health = 100;
}

void Health::setDamage(Damage damage) {
	if (damage.getDamage() < health)
		health -= damage.getDamage();
	else
		health = 0;
}

int Health::getHealth() {
	return health;
}