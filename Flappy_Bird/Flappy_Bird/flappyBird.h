#pragma once
#include <olcConsoleGameEngine.h>
#include <iostream>
#include <string>
#include <vector>

class FlappyBird :
	public olcConsoleGameEngine
{
public:
	FlappyBird();
	~FlappyBird();
	
	std::string m_sAppname;

protected:
	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);
private:
	//features describing flappy bird
	float fBirdPosition = 0.0f;
	float fBirdVelocity = 0.0f;
	float fBirdAcceleration = 0.0f;
	float fGravity = 100.0f;
	float fLevelPosition = 0.0f;

	float fSectionWidth;
	std::list<int> listSection;

	bool bHasCollided = false;
	bool bResetGame = false;

	int nAttemptCount = 0;
	int nFlapCount = 0;
	int nMaxFlapCount = 0;


	
};

