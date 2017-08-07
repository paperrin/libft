/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 20:08:06 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/07 20:14:04 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

t_color_rgb		ft_color_rgb(unsigned char r, unsigned char g
		, unsigned char b)
{
	return ((t_color_rgb){r, g, b});
}
