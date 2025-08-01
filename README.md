# OpenGL 3.3 C++ 3D Game Engine
This is a basic 3D Game Engine written in C++ utilizing OpenGL on Windows.

## Dependencies
The following dependencies must be installed via MSYS2:
- GLEW
- GLFW
- OpenGL
- GLM
- SDL2
- SFML

## Building The Engine
Run `build.bat`. This will generate a static library in /lib.

## Testing The Engine
Run `demo.bat` to test the Engine.

## Using The Engine
- Copy all header files from /include into your project directory.
- Link against Engine and the required dependencies.
- Build your project and run.

## Example Code
The following code shows how to render an object and play a sound file.
```cpp
#include "Engine/Engine.h"

int main()
{
    Engine::initialize();

    Engine::window->setWindowTitle("Game");

    Model example = Model("example.obj", "example.bmp");

    Sound sfx = Sound("example.wav");
    sfx.play();

    while (!Engine::window->shouldClose())
    {
        Engine::camera->update();

        Engine::renderer->update();
        Engine::renderer->renderModel(example);

        Engine::window->update();
    }

    Engine::window->closeWindow();
    return 0;
}
```

## Note
This engine is only a demo and has been discontinued.