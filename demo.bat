@echo off
g++ source\demo.cpp -Iinclude -Llib -lEngine -lglew32 -lglfw3 -lopengl32 -lSDL2main -lSDL2 -o bin\demo.exe
bin\demo.exe