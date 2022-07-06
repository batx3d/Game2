#include "Player.h"

#include <iostream>

Player::Player(GameScene* scene, Vector2i size) : GameObject(scene, "Player", NULL, size) {
    Textures* textures = new Textures();
    textures->addTexture(0, "Textures/Humans/Human.png");
    textures->addTexture(1, "Textures/Humans/Human_bottom.png");
    textures->addTexture(2, "Textures/Humans/Human_left.png");
    textures->addTexture(3, "Textures/Humans/Human_right.png");
    setTextures(textures);
    setTexture(0);
}

void Player::run(int time)
{
    float maxModule = 0.23;
    float maxSpeed = 0.3;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (speed.getY() == 0)
            speed = { maxSpeed, speed.getY() };
        else
            speed = { maxModule, speed.getY() };
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (speed.getY() == 0)
            speed = { -maxSpeed, speed.getY() };
        else
            speed = { -maxModule, speed.getY() };
    }
    else
        speed = { 0, speed.getY() };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (speed.getX() == 0)
            speed = { speed.getX(), maxSpeed };
        else
            speed = { speed.getX(), maxModule };
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (speed.getX() == 0)
            speed = { speed.getX(), -maxSpeed };
        else
            speed = { speed.getX(), -maxModule };
    }
    else
        speed = { speed.getX(), 0 };

    float newPositionsX = positions.getX() + time * speed.getX();
    float newPositionsY = positions.getY() + time * speed.getY();

    if (!getScene()->isWall({ newPositionsX, positions.getY() }, size))
        positions = { newPositionsX, positions.getY() };
    if (!getScene()->isWall({ positions.getX(), newPositionsY }, size))
        positions = { positions.getX(), newPositionsY };

    if (speed.getX() == 0 && speed.getY() >= 0)
        setTexture(0);
    else if (speed.getX() == 0 && speed.getY() < 0)
        setTexture(1);
    else if (speed.getX() < 0)
        setTexture(3);
    else if (speed.getX() > 0)
        setTexture(2);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (timer >= frequency) {
            Window* window = getScene()->getWindow();
            Vector2i mousePosition = window->getMousePosition();

            float x = mousePosition.getX() - getCenter().getX(), y = mousePosition.getY() - getCenter().getY();
            float difference = sqrt(x * x + y * y) / 0.65;  //0.7 - module speed bullet

            getScene()->addObject(new Bullet(getScene(), getCenter(), { x / difference, y / difference }, Damage(10)));

            timer = 0;
        }
    }

    if (timer < frequency)
        timer += time;
}