@echo off
g++ source/main.cpp source/Engine/Engine.cpp source/Engine/window.cpp source/Engine/renderer.cpp source/Engine/model.cpp source/Engine/utils.cpp source/Engine/camera.cpp source/Engine/sprite.cpp -Iinclude -Llibraries -lglew32 -lglfw3 -lopengl32 -o bin/main.exe
bin\main