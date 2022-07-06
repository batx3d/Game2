
#include "../Engine/GameScene.h"
#include "../Engine/Window.h"

using namespace Engine;

int main()
{
    Textures* texturesLevels = new Textures();
    texturesLevels->addTexture(1, "wall.png");

    //GameScene oneLevel = GameScene(44, 28, 50, texturesLevels);
    Engine::Window window(1100, 700, "Game", false);
    window.launch();

    return 0;
}