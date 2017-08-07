/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:56:33 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/07 18:58:53 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>

t_vec2i			ft_vec2i(int x, int y)
{
	t_vec2i		ret;

	ret = (t_vec2i){
		.x = x,
		.y = y
	};
	return (ret);
}

t_vec2i			*ft_vec2i_new(int x, int y)
{
	t_vec2i		*ret;

	ret = (t_vec2i*)malloc(sizeof(t_vec2i));
	if (ret)
		*ret = ft_vec2i(x, y);
	return (ret);
}
