@echo off
g++ source\main.cpp -Iinclude -Llibrary -lengine -o bin\main.exe
bin\main.exe
del bin\main.exe