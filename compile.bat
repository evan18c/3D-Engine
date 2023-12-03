@echo off
g++ source\Engine\*.cpp -Iinclude -lglew32 -lglfw3 -lopengl32 -lSDL2main -lSDL2 -shared -o bin\engine.dll