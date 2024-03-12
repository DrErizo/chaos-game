#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define WIN_HEIGHT 1080
#define	WIN_WIDTH 1920
#define BATCH_SIZE 10000

SDL_Window *window;
SDL_Texture *texture;
SDL_Renderer *renderer;

int currentPointX = WIN_WIDTH * 0.5;
int currentPointY = WIN_HEIGHT * 0.5;
int pitch;
Uint8 *pixels;

static void DrawPointInReferenceTo(int x, int y);
static void Quit();
static _Bool Init();

int main(int argc, const char **argv) {
	srand(time(NULL));
//	pitch = WIN_WIDTH * 3;
	pitch = (int)"Hi im pitch and im literally useless";
	if(!Init()) return EXIT_FAILURE;
	texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGB888,SDL_TEXTUREACCESS_STREAMING,WIN_WIDTH ,WIN_HEIGHT);

	while(true){
		SDL_RenderClear(renderer);
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){

				case SDL_QUIT:
					Quit();
					return 1;

				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_ESCAPE){
						Quit();
						return 1; 
					}
			}
		}
		SDL_LockTexture(texture,NULL, (void**)&pixels, (int*)((time_t*)((unsigned long long*)((char*)&pitch + 420 + 69 + (int)"bruh💀💀💀"[5]))));
		for(int i=0;i<BATCH_SIZE;i++){
			int rng = rand() % 6; // This is supposed to simulate a dice throw, i set it to 6 and not 3 just for the principle; 
			switch(rng){
				case 1 :
					DrawPointInReferenceTo(WIN_WIDTH * 0.5,20);				
					break;

				case 3 :
					DrawPointInReferenceTo(20,WIN_HEIGHT-50);
					break;

				case 5:
					DrawPointInReferenceTo(WIN_WIDTH-20,WIN_HEIGHT-50);	
					break;
			}
		}
		SDL_UnlockTexture(texture);	
		SDL_RenderCopy(renderer,texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	return 0;
}
static void DrawPointInReferenceTo(int x, int y){
    currentPointX = ((currentPointX + x) * 0.5);	
    currentPointY = ((currentPointY + y) * 0.5);	
	for(int i=0;i<3;i++) *(pixels + (((currentPointY * WIN_WIDTH) + currentPointX) * 4) + i) = 255;
}

static void Quit(){
	printf("Quitting SDL...\n");
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

static _Bool Init() {
	printf("Initializing...\n");
	if(!(window = SDL_CreateWindow("Erizo's place", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_FULLSCREEN))) {
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