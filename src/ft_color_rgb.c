/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 20:08:06 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/30 04:26:48 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

t_color_rgb		ft_color_rgb(unsigned char r, unsigned char g
		, unsigned char b)
{
	return ((t_color_rgb){r, g, b});
}

t_color_rgb		ft_color_interpolate(t_color_rgb a, t_color_rgb b, float v)
{
	t_color_rgb		color;

	color.r = a.r + ((int)b.r - a.r) * v;
	color.g = a.g + ((int)b.g - a.g) * v;
	color.b = a.b + ((int)b.b - a.b) * v;
	return (color);
}
