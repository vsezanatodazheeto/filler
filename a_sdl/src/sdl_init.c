/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:37:15 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/16 06:32:25 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler_v.h"

int				init()
{
	//Initialize PNG loading
	int flags;

	flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags))
	{
		ft_printf("{red}SDL_image could not initialize!{eoc}\n");
		return (1);
	}
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (1);
	if (TTF_Init() != 0)
		return (1);
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		ft_printf("{blue}linear texture filtering not enabled!{eoc}\n");
	return (0);
}

int				create(SDL_Window **win, SDL_Renderer **rend)
{
	Uint32 render_flags;

	render_flags = SDL_RENDERER_ACCELERATED;
	if(init() != 0)
		return (1);
	//Create window
    if (!(*win = SDL_CreateWindow("Filler",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGHT,
									SDL_WINDOW_FULLSCREEN_DESKTOP)))
		return (1);
	//Create renderer for window
	if (!(*rend = SDL_CreateRenderer(*win, -1, render_flags)))
		return (1);
	else
		SDL_SetRenderDrawColor(*rend, 0xFF, 0xFF, 0xFF, 0xFF);
    return (0);
}

int				load(SDL_Renderer **rend, SDL_Texture **bg, SDL_Texture **m_key, SDL_Texture **m_filler, SDL_Texture **m_p1, SDL_Texture **m_p2, SDL_Texture **m_corona)
{
    if(!(*bg = load_texture(&(*rend), "resources/checker.png")))
	{
		ft_printf("{red}failed to load texture image!{eoc}\n");
        return (1);
	}
    if(!(*m_key = load_texture(&(*rend), "resources/bg.png")))
	{
		ft_printf("{red}failed to load texture image!{eoc}\n");
        return (1);
	}
	if(!(*m_filler = load_texture(&(*rend), "resources/bg.png")))
	{
		ft_printf("{red}failed to load texture image!{eoc}\n");
        return (1);
	}
    if(!(*m_p1 = load_texture(&(*rend), "resources/bg.png")))
	{
		ft_printf("{red}failed to load texture image!{eoc}\n");
        return (1);
	}
    if(!(*m_p2 = load_texture(&(*rend), "resources/bg.png")))
	{
		ft_printf("{red}failed to load texture image!{eoc}\n");
        return (1);
	}
	if(!(*m_corona = load_texture(&(*rend), "resources/corona_2.png")))
	{
		ft_printf("{red}failed to load texture image!{eoc}\n");
        return (1);
	}
    return (0);
}

int				quit(SDL_Window **win, SDL_Renderer **rend, SDL_Texture **bg, SDL_Texture **m_key,
					 SDL_Texture **m_p1, SDL_Texture **m_p2)
{
	SDL_DestroyTexture(*bg);
	*bg = NULL;
	SDL_DestroyTexture(*m_key);
	*m_key = NULL;
	SDL_DestroyTexture(*m_p1);
	*m_p1 = NULL;
	SDL_DestroyTexture(*m_p2);
	*m_p2 = NULL;
	SDL_DestroyRenderer(*rend);
	*rend = NULL;
	SDL_DestroyWindow(*win);
	*win = NULL;
    SDL_Quit();
    IMG_Quit();
    return 0;
}

SDL_Texture		*load_texture(SDL_Renderer **rend, char *path)
{
	SDL_Texture *new_textur = NULL;
	SDL_Surface *loaded_scr;
	
	if(!(loaded_scr = IMG_Load(path)))
	{
		ft_printf("{red}unable to load image!{eoc}\n");
		return (NULL);
	}
	else
		new_textur = SDL_CreateTextureFromSurface(*rend, loaded_scr);
	SDL_FreeSurface(loaded_scr);
	return (new_textur);
}