@echo off
g++ -c source\Engine\camera.cpp -Iinclude
g++ -c source\Engine\Engine.cpp -Iinclude
g++ -c source\Engine\model.cpp -Iinclude
g++ -c source\Engine\physics.cpp -Iinclude
g++ -c source\Engine\renderer.cpp -Iinclude
g++ -c source\Engine\sound.cpp -Iinclude
g++ -c source\Engine\sprite.cpp -Iinclude
g++ -c source\Engine\text.cpp -Iinclude
g++ -c source\Engine\utils.cpp -Iinclude
g++ -c source\Engine\window.cpp -Iinclude
mkdir lib
ar rcs lib\libEngine.a camera.o Engine.o model.o physics.o renderer.o sound.o sprite.o text.o utils.o window.o
del *.o