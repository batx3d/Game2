#include "Bullet.h"

Bullet::Bullet(GameScene* scene, Vector2f positions, Vector2f speed, Damage damage) :
	GameObject(scene, "Bullet", NULL, {11, 11}), damage(damage)
{
    Textures* textures = new Textures();
    textures->addTexture(0, "Textures/Bullets/Bullet.png");

    setTextures(textures);
    setTexture(0);
    setPositions(positions);
    setSpeed(speed);
}

void Bullet::run(int time) {
    Vector2f newPositions = { getPositions().getX() + speed.getX() * time, getPositions().getY() + speed.getY() * time };  //TODO: in static functions to Functions class

    if (!scene->isWall(newPositions, size)) {
        setPositions(newPositions);
    }
    else
        setStatusDelete(true);
}

Damage Bullet::getDamage() {
    return damage;
}