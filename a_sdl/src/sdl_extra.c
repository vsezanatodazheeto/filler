/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:53:36 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/29 01:40:03 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/sdl.h"

void				change_blend(SDL_BlendMode b1, SDL_BlendMode b2)
{
	b1 = BLEND_ON;
	b2 = BLEND_OFF;
	return ;
}

SDL_Texture			*load_texture(SDL_Renderer **rend, char *path)
{
	SDL_Texture *new_textur = NULL;
	SDL_Surface *loaded_scr;
	
	if(!(loaded_scr = IMG_Load(path)))
	{
		ft_printf("{red}unable to load image in LOAD_TEXTURE!{eoc}\n");
		return (NULL);
	}
	else
		new_textur = SDL_CreateTextureFromSurface(*rend, loaded_scr);
	SDL_FreeSurface(loaded_scr);
	return (new_textur);
}

SDL_Texture			*load_font(SDL_Renderer **rend, char *path, int size, SDL_Color clr)
{
    TTF_Font		*sans = TTF_OpenFont("resources/zb.ttf", size);
	SDL_Texture 	*new_textur = NULL;
	SDL_Surface 	*loaded_scr;
	if(!(loaded_scr = TTF_RenderText_Blended(sans, path, clr)))
	{
		ft_printf("{red}unable to load image in LOAD_FONT!{eoc}\n");
		return (NULL);
	}
	else
		new_textur = SDL_CreateTextureFromSurface(*rend, loaded_scr);
	SDL_FreeSurface(loaded_scr);
	return (new_textur);
}