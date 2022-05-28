#include <SDL2/SDL.h>
#include <stdio.h>

#define WIN_HEIGHT 1000
#define WIN_WIDTH 1000
SDL_Window* window;
SDL_Event event;
SDL_Renderer* renderer;
uint8_t isRunning = 1;
int currentPointX = 500;
int currentPointY = 500;
int main(int argc, const char **argv) {
	printf("Initializing...\n");
        if((window = SDL_CreateWindow("Erizo's place", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN))){
                printf("Window Initialized\n");
        }
        if((renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))){
                printf("Renderer Initialized\n");
        }  
        while(isRunning){
		while(SDL_PollEvent(&event)){
                        switch(event.type){
                                case SDL_QUIT:
                                        printf("Quitting SDL...\n");
                                        SDL_Quit();
                                        break;
                                case SDL_KEYDOWN:
                                        if(event.key.keysym.sym == SDLK_ESCAPE){
                                                printf("Quitting SDL...\n");
                                                SDL_Quit();
                                        }
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

		SDL_RenderDrawPoint(renderer, 500,20);
		SDL_RenderDrawPoint(renderer, 20,800);
		SDL_RenderDrawPoint(renderer, 980,800);
		SDL_RenderDrawPoint(renderer,500,500);
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		
		SDL_RenderPresent(renderer);
        }
        return 0;
}
int DrawPointInReferenceTo(int x,int y){
	SDL_RenderDrawPoint(renderer,((currentPointX * 0.5) + x * 0.5), ((currentPointY * 0.5) + y * 0.5));
	currentPointX = ((currentPointX * 0.5) + x * 0.5);	
	currentPointY = ((currentPointY * 0.5) + y * 0.5);	
		return 1;	
}

void SDL_Quit(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        isRunning = 0;
}
