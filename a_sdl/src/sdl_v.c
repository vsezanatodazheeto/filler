/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 06:27:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/12 07:21:48 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"
#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
#include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"

void	init_v()
{
	// инициализация SDL2
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error initializing SDL: %s\n", SDL_GetError());
	// создаем окно, центрированное размеров 640 x 640
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("CS: 1.6 2D",
							  SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,
							  640, 640,
							  0);
	//...
	// создаем поверхность, на которой все будем отрисовывать, присваеваем ей всякую хуйню
	SDL_Surface *screen_surface = NULL;
	screen_surface = SDL_GetWindowSurface(window);
	SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 123, 255, 255));
	SDL_UpdateWindowSurface(window);
	//...
	int close = 0;
	while (!close)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type)
			{
				if (event.type == SDL_QUIT)
					close = 1;
				break;
			}
		}
		SDL_Delay(1000 / 60);
	}

	// фришим всякую хуйню
	SDL_DestroyWindow(window);
	SDL_Quit();
	return ;
}