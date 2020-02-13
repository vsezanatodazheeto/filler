/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:05:08 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/13 22:44:24 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler_v.h"

void        reading_to_struct(t_filler *filler, char **line)
{
	while (get_next_line(0, &(*line)))
	{
		if (**line == 'P' && ft_is_strstr(*line, NAME_FIELD))
		{
			record_map(filler, &(*line));
			record_map_positions(filler, &(*line));
		}
		else if (**line == 'P' && ft_is_strstr(*line, NAME_PIECE))
		{
			record_piece(filler, &(*line));
			record_piece_positions(filler, &(*line));
		}
		else if (**line == '<' && ft_is_strstr(*line, NAME_GOT))
		{
			record_got_pos(filler, &(*line));
			return ;
		}
	}
	return ;
}

void    add_struct(t_filler *cur_lst)
{
        t_filler  *ptr;

        ptr = new_t_filler();
        cur_lst->next = ptr;
        return ;
}

int main() 
{ 
    t_filler    *cur_lst;
    t_filler	*fst_lst;
	t_piece		*piece;
	t_map		*map;
	t_pos		*pos;
	char 		*line;
	int			i;

	i  = 0;
    fst_lst = new_t_filler();
	cur_lst = fst_lst;
    line = NULL;
	check_player(cur_lst, &line);
    while(++i < 12)
    {
        map = new_t_map();
        pos = new_t_pos();
        piece = new_t_piece();
        init_structs(cur_lst, piece, map, pos);
        reading_to_struct(cur_lst, &line);
        add_struct(cur_lst);
        print_everything(cur_lst);
        cur_lst = cur_lst->next;
    }
    main_v();





















	// SDL_Window *window = SDL_CreateWindow("name of window",
	// 									  SDL_WINDOWPOS_CENTERED,
	// 									  SDL_WINDOWPOS_CENTERED,
	// 									  1080, 1080, 0);
	// // triggers the program that controls
	// // your graphics hardware and sets flags
	// Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	// // creates a renderer to render our images
	// SDL_Renderer *rend = SDL_CreateRenderer(window, -1, render_flags);

	// // creates a surface to load an image into the main memory 
    // SDL_Surface* surface; 
  
    // // please provide a path for your image 
    // surface = IMG_Load("zubr.png"); 
  
    // // loads image to our graphics hardware memory. 
    // SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface); 
  
    // // clears main-memory 
    // SDL_FreeSurface(surface); 
  
    // // let us control our image position 
    // // so that we can move it with our keyboard. 
    // SDL_Rect dest; 
  
    // // connects our texture with dest to control position 
    // SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h); 
  
    // // adjust height and width of our image box. 
    // dest.w /= 6; 
    // dest.h /= 6; 
  
    // // sets initial x-position of object 
    // dest.x = (1000 - dest.w) / 2; 
  
    // // sets initial y-position of object 
    // dest.y = (1000 - dest.h) / 2; 
  
    // // controls annimation loop 
    // int close = 0; 
  
    // // speed of box 
    // int speed = 3000; 
  
    // // annimation loop 
    // while (!close) { 
    //     SDL_Event event; 
  
    //     // Events mangement 
    //     while (SDL_PollEvent(&event)) { 
    //         switch (event.type) { 
  
    //         case SDL_QUIT: 
    //             // handling of close button 
    //             close = 1; 
    //             break; 
  
    //         case SDL_KEYDOWN: 
    //             // keyboard API for key pressed 
    //             switch (event.key.keysym.scancode) { 
    //             case SDL_SCANCODE_W: 
    //             case SDL_SCANCODE_UP: 
    //                 dest.y -= speed / 30; 
    //                 break; 
    //             case SDL_SCANCODE_A: 
    //             case SDL_SCANCODE_LEFT: 
    //                 dest.x -= speed / 30; 
    //                 break; 
    //             case SDL_SCANCODE_S: 
    //             case SDL_SCANCODE_DOWN: 
    //                 dest.y += speed / 30; 
    //                 break; 
    //             case SDL_SCANCODE_D: 
    //             case SDL_SCANCODE_RIGHT: 
    //                 dest.x += speed / 30; 
    //                 break; 
    //             } 
    //         } 
    //     } 
  
    //     // right boundary 
    //     if (dest.x + dest.w > 1000) 
    //         dest.x = 1000 - dest.w; 
  
    //     // left boundary 
    //     if (dest.x < 0) 
    //         dest.x = 0; 
  
    //     // bottom boundary 
    //     if (dest.y + dest.h > 1000) 
    //         dest.y = 1000 - dest.h; 
  
    //     // upper boundary 
    //     if (dest.y < 0) 
    //         dest.y = 0; 
  
    //     // clears the screen 
    //     SDL_RenderClear(rend); 
    //     SDL_RenderCopy(rend, tex, NULL, &dest); 
  
    //     // triggers the double buffers 
    //     // for multiple rendering 
    //     SDL_RenderPresent(rend); 
  
    //     // calculates to 60 fps 
    //     SDL_Delay(1000 / 60); 
    // } 
  
    // // destroy texture 
    // SDL_DestroyTexture(tex); 
  
    // // destroy renderer 
    // SDL_DestroyRenderer(rend); 
  
    // // destroy window 
    // SDL_DestroyWindow(window); 
    return 0; 
} 