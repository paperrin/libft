/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_env_aaline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 02:36:07 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/09 06:13:23 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"
#include <stdio.h>

static void		plot(t_graph_env *env, int x, int y, int a)
{
	if (a > 254)
		a = 254;
	(*env->f_put_pixel)(ft_vec3f(x, y, 0), ft_color_rgb(a, 0, 0), env->put_pixel_param);
}

static void		draw_line(t_graph_env *env
	, t_vec2i a, t_vec2i b, float width)
{
	const t_vec2i	d = ft_vec2i(ABS(b.x - a.x), ABS(b.y - a.y));
	const t_vec2i	s = ft_vec2i(a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1);
	int				err = d.x - d.y;
	int				err2;
	t_vec2i			c;
	float			ed = d.x + d.y == 0
		? 1 : sqrt((float)d.x * d.x + (float)d.y * d.y);

	width = (width + 1) / 2;
	while (1)
	{
		plot(env, a.x, a.y, 255 - 255 * (abs(err - d.x + d.y) / ed - width + 1));
		err2 = err;
		c.x = a.x;
		if (2 * err2 >= -d.x)
		{
			err2 += d.y;
			c.y = a.y;
			while (err2 < ed * width && (b.y != c.y || d.x > d.y))
			{
				c.y += s.y;
				plot(env, a.x, c.y, 255 - 255 * (abs(err2) / ed - width + 1));
				if (d.y == 0)
					plot(env, a.x, a.y + (a.y - c.y), 255 - 255 * (abs(err2) / ed - width + 1));
				err2 += d.x;
			}
			if (a.x == b.x)
				break ;
			err2 = err;
			err -= d.y;
			a.x += s.x;
		}
		if (2 * err2 <= d.y)
		{
			err2 = d.x - err2;
			while (err2 < ed * width && (b.x != c.x || d.x < d.y))
			{
				c.x += s.x;
				plot(env, c.x, a.y, 255 - 255 * (abs(err2) / ed - width + 1));
				if (d.x == 0)
					plot(env, a.x + (a.x - c.x), a.y, 255 - 255 * (abs(err2) / ed - width + 1));
				err2 += d.y;
			}
			if (a.y == b.y)
				break ;
			err += d.x;
			a.y += s.y;
		}
	}
}

void			ft_graph_env_aaline(t_graph_env *env, t_vec2i a, t_vec2i b
	, float width)
{
	t_matrix	*mx;

	mx = (t_matrix*)ft_array_back(&env->matrices);
	draw_line(env, ft_vec2i_transform(&a, mx)
		, ft_vec2i_transform(&b, mx), width);
}
