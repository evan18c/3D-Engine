// Engine
#include "Engine/Engine.h"

// This main function is a demo on how to use the core features of the game engine
int main(void)
{

    // Initialize Engine
    Engine::initialize();

    // Changing title
    Engine::window->setWindowTitle("Game");

    // Create Model
    Model model = Model("assets/objs/PLATFORM.obj", "assets/bmps/PLATFORM.bmp");

    // Create Sprite
    Sprite sprite = Sprite("assets/sprites/HUD.bmp");

    // Create sound and play
    Sound sfx = Sound("assets/wavs/ding.wav");
    sfx.play();

    // Engine
    while (!Engine::window->shouldClose())
    {
        // Update Camera
        Engine::camera->update();

        // Update window title fps
        std::string title = "3D Endgine. FPS: " + std::to_string(Engine::window->getFPS());
        Engine::window->setWindowTitle(title.c_str());

        // Rendering
        Engine::renderer->update();
        Engine::renderer->renderModel(model);
        Engine::renderer->renderSprite(sprite);

        // Swap screen buffers and poll for events
        Engine::window->update();
    }

    // End
    Engine::window->closeWindow();
    return 0;
}