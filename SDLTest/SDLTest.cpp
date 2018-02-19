// SDLTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
		return EXIT_FAILURE;
	} else {
		std::cout << "SDL initialization succeeded!";
	}

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Wait two seconds
	SDL_Delay(2000);

	//Fill the surface red
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x0, 0x0));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Wait two seconds
	SDL_Delay(2000);

	//Fill the surface green
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x0, 0xff, 0x0));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Wait two seconds
	SDL_Delay(2000);

	//Fill the surface blue
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x0, 0x0, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Wait two seconds
	SDL_Delay(2000);

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return EXIT_SUCCESS;
}