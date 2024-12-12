/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:01:00 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 18:01:10 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "types.h"

typedef struct s_renderer
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_renderer;

typedef struct s_data_addr
{
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_data_addr;

t_renderer				*new_renderer(char *title, t_size size);
void					del_renderer(t_renderer *renderer);

int						get_data_addr(void *img, t_data_addr *data_addr);

#endif