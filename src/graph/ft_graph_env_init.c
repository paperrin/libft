/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_env_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:20:04 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/04 12:17:31 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

int				ft_graph_env_init(t_graph_env *env
	, void (*f_put_pixel)(t_vec3f pos, t_color_rgb color, void *param)
	, void *put_pixel_param)
{
	t_matrix	*mx;

	env->f_put_pixel = f_put_pixel;
	env->put_pixel_param = put_pixel_param;
	env->matrices = ft_array_init(NULL);
	if (!ft_array_reserve(&env->matrices, 0, 10))
		return (0);
	if (!(mx = ft_matrix_new()))
		return (0);
	ft_matrix_to_identity(mx);
	ft_array_push_back(&env->matrices, mx);
	return (1);
}
