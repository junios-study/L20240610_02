#include <iostream>

using namespace std;

#include "SDL.h"


#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")


int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Init error" << endl;
		return -1;
	}

	SDL_Window* MyWindow = SDL_CreateWindow("Simple GameEngine", 100, 100, 640, 480, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	bool IsRunning = true;
	SDL_Event MyEvent;
	while (IsRunning)
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			IsRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			cout << "Mouse Button Down" << endl;
			break;
		}

		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
		SDL_RenderClear(MyRenderer);

		SDL_RenderPresent(MyRenderer);

	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}