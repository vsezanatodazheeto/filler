/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:53:36 by yshawn            #+#    #+#             */
/*   Updated: 2020/03/04 14:14:38 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vis_filler.h"
#include "../../include/vis_sdl.h"

int					score_recount(t_rend *r, t_f *lst)
{
	r->event->str_score = ft_itoa(lst->ally_cnt * 100 / r->event->mapsize);
	SDL_DestroyTexture(r->f->p1_score);
	if (!(r->f->p1_score = load_font(&(r->rend), r->event->str_score, FONT_SIZE, white)))
	{
		ft_memdel((void **)&r->event->str_score);
		return (1);
	}
	ft_memdel((void **)&r->event->str_score);
	r->event->str_score = ft_itoa(lst->enemy_cnt * 100 / r->event->mapsize);
	r->event->str_score = ft_strnew_size(&r->event->str_score, 3);
	SDL_DestroyTexture(r->f->p2_score);
	if (!(r->f->p2_score = load_font(&(r->rend), r->event->str_score, FONT_SIZE, white)))
	{
		ft_memdel((void **)&r->event->str_score);
		return (1);
	}
	ft_memdel((void **)&r->event->str_score);
	return (0);
}

void				blendmode_swap(t_rend *r)
{
	if (r->blend_p == BLEND_OFF)
	{
		r->blend_p = BLEND_ON;
		r->blend_r = BLEND_OFF;
	}
	else
	{
		r->blend_p = BLEND_OFF;
		r->blend_r = BLEND_ON;
	}
	return ;
}

SDL_Texture			*load_texture(SDL_Renderer **rend, char *path)
{
	SDL_Texture		*new_textur = NULL;
	SDL_Surface		*loaded_scr;

	if (!(loaded_scr = IMG_Load(path)))
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
	TTF_Font		*sans = TTF_OpenFont(PATH_TTF, size);
	SDL_Texture		*new_textur = NULL;
	SDL_Surface		*loaded_scr;

	if (!sans)
	{
		ft_printf("{red}unable to load font in LOAD_FONT!{eoc}\n");
		return (NULL);
	}
	if (!(loaded_scr = TTF_RenderText_Blended(sans, path, clr)))
	{
		ft_printf("{red}unable to load image in LOAD_FONT!{eoc}\n");
		return (NULL);
	}
	else
		new_textur = SDL_CreateTextureFromSurface(*rend, loaded_scr);
	TTF_CloseFont(sans);
	SDL_FreeSurface(loaded_scr);
	return (new_textur);
}
