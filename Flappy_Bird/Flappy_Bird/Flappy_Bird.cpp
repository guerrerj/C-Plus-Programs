// Flappy_Bird.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "olcConsoleGameEngine.h"
#include "flappyBird.h"


int main()
{
	FlappyBird game;
	game.ConstructConsole(80, 48, 16, 16);
	game.Start();

	return 0;
}

