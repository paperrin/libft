/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:57:00 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/30 04:23:39 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include "ft_math.h"
# include "ft_color.h"
# include "ft_array.h"

typedef struct		s_edge
{
	int				y_max;
	int				y_min;
	int				x;
	t_color_rgb		color_max;
	t_color_rgb		color_min;
	t_color_rgb		color;
	int				sign;
	int				dx;
	int				dy;
	float			sum;
}					t_edge;

t_array			*ft_graph_create_edge_table(t_vec3f *vertices
	, t_color_rgb *colors, size_t n);
int				ft_graph_poly_fill(t_array *edges
	, void (*f_put_pixel)(t_vec3f pos, t_color_rgb color, void *param)
	, void *param);

#endif
