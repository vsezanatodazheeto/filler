/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/10 23:20:04 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frameworks/SDL2.framework/Headers/SDL.h"
#include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "frameworks/SDL2_image.framework/Headers/SDL_image.h"
#include "frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
#include "sdl.h"

void		printf_map(t_filler *filler)
{
	int 	i;
	int		j;
	int		x;
	int		xx;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	xx = 0;
	y = 0;

	ft_printf("    ");
	while (x < filler->map->width)
	{
		if (xx > 9)
			xx = 0;
		ft_printf("%d", xx);
		x++;
		xx++;
	}
	ft_printf("\n");
	while (i < filler->map->height)
	{
		j = 0;
		ft_printf("%3d ", y);
		while (j < filler->map->width)
		{
			if (filler->map->map[i][j] == -1)
				ft_printf("{green}O");
			else if (filler->map->map[i][j] == -2)
			{
				ft_printf("{red}X");
			}
			else
				ft_printf("{eoc}.");
			j++;
		}
		ft_printf("\n");
		i++;
		y++;
	}
		ft_printf("\n");
	return ;
}

void		record_piece_positions(t_filler *filler, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < filler->piece->height && get_next_line(0, &(*line)))
	{
		j = 0;
		while (j < filler->piece->width)
		{
			if ((*line)[j] == '.')
				filler->piece->piece[i][j] = 0;
			if ((*line)[j] == '*')
				filler->piece->piece[i][j] = 1;
			j++;
		}
		i++;
	}
	return ;
}

void		record_piece(t_filler *filler, char **line)
{	
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->piece->height = ft_atoi(*(tmp + 1));
	filler->piece->width = ft_atoi(*(tmp + 2));
	ft_memdel((void **)tmp);
	if (!(filler->piece->piece = (int **)malloc(sizeof(int *) * filler->piece->height)))
		exit(1);
	while (j < filler->piece->height)
	{
		if (!(filler->piece->piece[j] = (int *)malloc(sizeof(int) * filler->piece->width)))
			exit(1);
		j++;
	}
	return ;
}

void		record_map_positions(t_filler *filler, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < filler->map->height && get_next_line(0, &(*line)))
	{
		j = 0;
		while (j < filler->map->width)
		{
			if ((*line + HGT)[j] == '.')
				filler->map->map[i][j] = 0;
			else if (ft_toupper((*line + HGT)[j]) == 'O' || ft_toupper((*line + HGT)[j]) == 'X')
			{
				if ((filler->ally == 'O' && ft_toupper((*line + HGT)[j]) == 'O') ||
											(filler->ally == 'X' && ft_toupper((*line + HGT)[j]) == 'X'))
					filler->map->map[i][j] = -1;
				else
					filler->map->map[i][j] = -2;
			}
			j++;
		}
		i++;
	}
	return ;
}

void		record_map(t_filler *filler, char **line)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(*line, ' ');
	filler->map->height = ft_atoi(*(tmp + 1));
	filler->map->width = ft_atoi(*(tmp + 2));
	ft_memdel((void **)tmp);
	if (!(filler->map->map = (int **)malloc(sizeof(int *) * filler->map->height)))
		exit(1);
	while (j < filler->map->height)
	{
		if (!(filler->map->map[j] = (int *)malloc(sizeof(int) * filler->map->width)))
			exit(1);
		j++;
	}
	return ;
}

void		record_player(t_filler *filler, int i)
{
	if (i)
	{
		filler->ally = 'O';
		filler->enemy = 'X';
	}
	else
	{
		filler->ally = 'X';
		filler->enemy = 'O';
	}
}


int			ft_is_strstr(char *str_dad, char *str_son)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!*str_dad || !*str_son)
		return (FALSE);
	while (str_dad[i] && n == 0)
	{
		n = 0;
		if (str_dad[i] == str_son[n])
		{
			while (str_son[n] && str_dad[i])
			{
				if (str_son[n] != str_dad[i])
				{
					n = 0;
					break;
				}
				i++;
				n++;
			}
		}
		i++;
	}
	return ( n == 0 ? FALSE : i);
}

void		free_data(t_filler *filler, char **line)
{
	if (filler->map->map)
		ft_memdel((void **)&filler->map->map);
	if (filler->piece->piece)
		ft_memdel((void **)&filler->piece->piece);
	if (line)
		ft_memdel((void **)&line);
	return ;
}

void 		init_structs(t_filler *filler, t_piece *piece, t_map *map, t_pos *pos)
{
	filler->ally = '\0';
	filler->enemy = '\0';
	filler->piece = NULL;
	filler->map = NULL;
	filler->pos = NULL;
	piece->width = 0;
	piece->height = 0;
	piece->piece = NULL;
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	pos->i = 0;
	pos->j = 0;
	pos->x = 0;
	pos->y = 0;
	filler->map = map;
	filler->piece = piece;
	filler->pos = pos;
    filler->next = NULL;
}

void        reading_to_struct(t_filler *filler, char **line)
{
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'P' && ft_is_strstr(*line, NAME_FIELD))
		{
			if (!filler->map->map)
				record_map(filler, &(*line));
			record_map_positions(filler, &(*line));
		}
		else if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
		{
			record_piece(filler, &(*line));
			record_piece_positions(filler, &(*line));
            // printf_map(filler);
			if (filler->pos->i == 0 && filler->pos->j == 0)
				return ;
			ft_printf("%d %d\n", filler->pos->i - 1, filler->pos->j);
			return ;
		}
	}
	return ;
}

void		check_starting_data(t_filler *filler, char **line)
{
	while (get_next_line(0, &(*line)))
	{
		if (**line == '$' && !filler->ally)
		{
			if (ft_is_strstr(*line, NAME_ALLY) && ft_is_strstr(*line, "p1"))
				record_player(filler, TRUE);
			else
				record_player(filler, FALSE);
			break ;
		}
	}
    return ;
}

t_filler  *new_struct()
{
        t_filler  *ptr;

        ptr = malloc(sizeof(t_filler));
        if (NULL == ptr) {
                return (NULL);
        }
        ptr->next = NULL;
        return ptr;
}

void    add_struct(t_filler *filler)
{
        t_filler  *ptr;

        ptr = new_struct();
        filler->next = ptr;
        return ;
}



int main() 
{ 
    t_filler    *current;
    t_filler	*filler;
	t_piece		piece[1];
	t_map		map[1];
	t_pos		pos[1];
	char 		*line;
	int			i;

	i  = 0;
    //reading from vm to list of structures
    filler = new_struct();
	current = filler;
    line = NULL;
	init_structs(current, piece, map, pos);
	check_starting_data(filler, &line);
    while(i < 100) {
		// printf("%s\n", line);
       	init_structs(current, piece, map, pos);
        reading_to_struct(current, &line);
        add_struct(current);
		printf_map(current);
        current = current->next;
		i++;
    }

    // returns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    } 
    SDL_Window* win = SDL_CreateWindow("ZAEBUMBA", // creates a window 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       640, 1080, 0); 
  
    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; 
    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags); 
  
    // creates a surface to load an image into the main memory 
    SDL_Surface* surface; 
  
    // please provide a path for your image 
    surface = IMG_Load("zubr.png"); 
  
    // loads image to our graphics hardware memory. 
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface); 
  
    // clears main-memory 
    SDL_FreeSurface(surface); 
  
    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest; 
  
    // connects our texture with dest to control position 
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h); 
  
    // adjust height and width of our image box. 
    dest.w /= 6; 
    dest.h /= 6; 
  
    // sets initial x-position of object 
    dest.x = (1000 - dest.w) / 2; 
  
    // sets initial y-position of object 
    dest.y = (1000 - dest.h) / 2; 
  
    // controls annimation loop 
    int close = 0; 
  
    // speed of box 
    int speed = 300; 
  
    // annimation loop 
    while (!close) { 
        SDL_Event event; 
  
        // Events mangement 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
  
            case SDL_QUIT: 
                // handling of close button 
                close = 1; 
                break; 
  
            case SDL_KEYDOWN: 
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) { 
                case SDL_SCANCODE_W: 
                case SDL_SCANCODE_UP: 
                    dest.y -= speed / 30; 
                    break; 
                case SDL_SCANCODE_A: 
                case SDL_SCANCODE_LEFT: 
                    dest.x -= speed / 30; 
                    break; 
                case SDL_SCANCODE_S: 
                case SDL_SCANCODE_DOWN: 
                    dest.y += speed / 30; 
                    break; 
                case SDL_SCANCODE_D: 
                case SDL_SCANCODE_RIGHT: 
                    dest.x += speed / 30; 
                    break; 
                } 
            } 
        } 
  
        // right boundary 
        if (dest.x + dest.w > 1000) 
            dest.x = 1000 - dest.w; 
  
        // left boundary 
        if (dest.x < 0) 
            dest.x = 0; 
  
        // bottom boundary 
        if (dest.y + dest.h > 1000) 
            dest.y = 1000 - dest.h; 
  
        // upper boundary 
        if (dest.y < 0) 
            dest.y = 0; 
  
        // clears the screen 
        SDL_RenderClear(rend); 
        SDL_RenderCopy(rend, tex, NULL, &dest); 
  
        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend); 
  
        // calculates to 60 fps 
        SDL_Delay(1000 / 60); 
    } 
  
    // destroy texture 
    SDL_DestroyTexture(tex); 
  
    // destroy renderer 
    SDL_DestroyRenderer(rend); 
  
    // destroy window 
    SDL_DestroyWindow(win); 
    return 0; 
} 