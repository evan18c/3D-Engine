@echo off
g++ source/GameDemo/main.cpp source/Engine/Engine.cpp source/Engine/window.cpp source/Engine/renderer.cpp source/Engine/model.cpp source/Engine/utils.cpp source/Engine/camera.cpp source/Engine/sprite.cpp source/Engine/text.cpp -Iinclude -Llibraries -lglew32 -lglfw3 -lopengl32 -o bin/game.exe
bin\game