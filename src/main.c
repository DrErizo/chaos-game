#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define WIN_HEIGHT 1000
#define WIN_WIDTH 1000

SDL_Window *window;
SDL_Renderer *renderer;
_Bool isRunning = true;
int currentPointX = 500;
int currentPointY = 500;

static void DrawPointInReferenceTo(int x, int y);
static void Quit();
static _Bool Init();

int main(int argc, const char **argv) {
	if(!Init())
		return EXIT_FAILURE;

        while(isRunning){
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);

		SDL_Event event;
		while(SDL_PollEvent(&event)){
                        switch(event.type){
                                case SDL_QUIT:
					Quit();
                                        break;

                                case SDL_KEYDOWN:
                                        if(event.key.keysym.sym == SDLK_ESCAPE)
                                                Quit();

                                        break; 
                        }
                }

		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		int rng = rand() % 6;
		switch(rng){
			case 1:
			case 2:
				DrawPointInReferenceTo(500,20);				
				break;

			case 3 :
			case 4 :
				DrawPointInReferenceTo(20,800);
				break;

			case 5:
			case 6:
				DrawPointInReferenceTo(980,800);	
				break;
		}

		SDL_RenderDrawPoint(renderer, 500, 20);
		SDL_RenderDrawPoint(renderer, 20, 800);
		SDL_RenderDrawPoint(renderer, 980, 800);
		SDL_RenderDrawPoint(renderer, 500, 500);
	
		SDL_RenderPresent(renderer);
        }

        return 0;
}

static void DrawPointInReferenceTo(int x, int y){
	SDL_RenderDrawPoint(renderer, ((currentPointX * 0.5) + x * 0.5), ((currentPointY * 0.5) + y * 0.5));
	currentPointX = ((currentPointX * 0.5) + x * 0.5);	
	currentPointY = ((currentPointY * 0.5) + y * 0.5);	
}

static void Quit(){
	printf("Quitting SDL...\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        isRunning = false;
}

static _Bool Init() {
	printf("Initializing...\n");

        if(!(window = SDL_CreateWindow("Erizo's place", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN))) {
		fprintf(stderr, "Failed to init SDL window: %s\n", SDL_GetError());
		return false;
	}
	printf("Window Initialized\n");

        if(!(renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))){
		fprintf(stderr, "Failed to init SDL renderer: %s\n", SDL_GetError());
		return false;
        }  
	printf("Renderer Initialized\n");

	return true;
}
