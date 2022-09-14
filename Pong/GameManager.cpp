#include "pch.h"
#include "GameManager.h"

GameManager::GameManager()
{
	_pongs.reserve(99);
}

void GameManager::AddPong(int32 width, int32 height, int32 x, int32 y)
{
	_pongs.emplace_back(width, height, x, y);
}

void GameManager::Tick()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto& i : _pongs) {
		i.Tick();
	}
	glutSwapBuffers();
	glutPostRedisplay();

	this_thread::sleep_for(16.6ms);
}

void GameManager::AddPong(int32 width, int32 height, int32 x, int32 y,char L, char R)
{
	_pongs.emplace_back(width,height,x,y,L,R);
}
