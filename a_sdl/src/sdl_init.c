/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/14 21:55:12 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

int init(SDL_Window **win, SDL_Renderer **rend, SDL_Surface **scr)
{
	//Initialize PNG loading
	int flags;
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags))
	{
		ft_printf("{red}SDL_image could not initialize!{eoc}\n");
        return (1);
	}
	//Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return (1);
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		ft_printf("{blue}linear texture filtering not enabled!{eoc}\n");
	//Create window
    if (!(*win = SDL_CreateWindow("Filler",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGHT,
									SDL_WINDOW_SHOWN)))
		return (1);
	//Create renderer for window
	if (!(*rend = SDL_CreateRenderer(*win, -1, render_flags)))
		return (1);
	else
		SDL_SetRenderDrawColor(*rend, 0xFF, 0xFF, 0xFF, 0xFF);
	// *scr = SDL_GetWindowSurface(*win);
    return 0;
}

SDL_Texture	*load_texture(SDL_Renderer **rend)
{
	SDL_Texture *new_textur = NULL;
	SDL_Surface *loaded_scr;
	
	if(!(loaded_scr = IMG_Load("resources/checker.png")))
	{
		ft_printf("{red}unable to load image!{eoc}\n");
		exit(1);
	}
	else
	{
		new_textur = SDL_CreateTextureFromSurface(*rend, loaded_scr);
	}
	SDL_FreeSurface(loaded_scr);
	return (new_textur);
}

int load(SDL_Texture **textur, SDL_Renderer **rend)
{
    if(!(*textur = load_texture(&(*rend))))
	{
		ft_printf("{red}failed to load texture image!{eoc}\n");
        return (1);
	}
    return 0;
}

int quit(SDL_Window **win, SDL_Renderer **rend, SDL_Texture **textur)
{
	SDL_DestroyTexture(*textur);
	*textur = NULL;
	SDL_DestroyRenderer(*rend);
	*rend = NULL;
	SDL_DestroyWindow(*win);
	*win = NULL;
    SDL_Quit();
    IMG_Quit();
    return 0;
}