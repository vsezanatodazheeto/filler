#include "../include/filler_v.h"

int main_v (int argc, char ** args) {
	SDL_Window *win = NULL;
	SDL_Surface *scr = NULL;
	SDL_Surface *john = NULL;
	SDL_Surface *bg = NULL;
	SDL_Surface *bower = NULL;

	if (init(&win, &scr) == 1)
		return 1;
	if (load(&john, &bg, &scr) == 1)
		return 1;

	SDL_Rect bg_cat;
    bg_cat.w = 680;
    bg_cat.h = 680;
    bg_cat.x = 0;
    bg_cat.y = 0;
	
	SDL_BlitScaled(john, NULL, scr, &bg_cat);

    SDL_UpdateWindowSurface(win);

    SDL_Delay(2000);

    int	run = TRUE;
    SDL_Event e;
    SDL_Rect r;

    int x = 0;
    int y = 0;

    r.x = x;
    r.y = y;

    while (run) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                run = FALSE;
            }

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) {
                    y -= 1;
                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    y += 1;
                }
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    x += 6;
                }
                if (e.key.keysym.sym == SDLK_LEFT) {
                    x -= 6;
                }
            }
        }
        r.x = x;
        r.y = y;

        SDL_FillRect(scr, NULL, SDL_MapRGB(scr -> format, 255, 255, 255));

        SDL_BlitSurface(bg, NULL, scr, &r);

        SDL_UpdateWindowSurface(win);
    }

    return quit(&win, &scr, &john);
}