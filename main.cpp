#include <iostream>

using namespace std;

#include "SDL.h"


#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")


SDL_Window* MyWindow;
SDL_Renderer* MyRenderer;
SDL_Event MyEvent;
bool IsRunning;


void Init();
void Input();
void Render();
void Tick();
void Term();

int SDL_main(int argc, char* argv[])
{
	Init();

	while (IsRunning)
	{
		Input();
		Tick();
		Render();
	}

	Term();

	return 0;
}

void Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Init error" << endl;
		return;
	}

	MyWindow = SDL_CreateWindow("Simple GameEngine", 100, 100, 640, 480, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE /*SDL_RENDERER_SOFTWARE*/);

	srand((unsigned int)(time(0)));

	IsRunning = true;
}

void Term()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
}

void Input()
{
	SDL_PollEvent(&MyEvent);
}

void Tick()
{
	switch (MyEvent.type)
	{
	case SDL_QUIT:
		IsRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		cout << "Mouse Button Down" << endl;
		break;
	case SDL_KEYDOWN:
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			IsRunning = false;
			break;
		}
	}
}

void Render()
{
	int R = rand() % 256;
	int G = rand() % 256;
	int B = rand() % 256;

	//ClearScreen
	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
	SDL_RenderClear(MyRenderer);

	//Render 
	SDL_SetRenderDrawColor(MyRenderer, R, G, B, 0);
	SDL_Rect MyRect;
	MyRect.x = rand() % 640;
	MyRect.y = rand() % 480;
	MyRect.w = rand() % 640;
	MyRect.h = rand() % 480;
	SDL_RenderFillRect(MyRenderer, &MyRect);

	SDL_RenderPresent(MyRenderer);
}

