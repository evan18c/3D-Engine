# OpenGL 3.3 C++ 3D Game Engine
This is a random 3D Game Engine written in C++ utilizing OpenGL on Windows.

## Requirements?
Use the pacman function on MSYS2 to install the following libraries:
- MSYS2
- g++
- OpenGL
- GLEW
- GLFW
- GLM

## How To Build?
Run `compile.bat` on the command line. This will create an engine.dll binary in /bin.

## How To Use?
- Copy the /assets, /include, and /shaders folders into a new directory.
- Add /include to your includes directory.
- Build your project and link with Engine.dll

## Starter Code
```cpp
#include "Engine/Engine.h"

int main()
{
    Engine::initialize();

    Engine::window->setWindowTitle("Game");

    Model example = Model("example.obj", "example.bmp");

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

## Why Use My Engine?
/shrug