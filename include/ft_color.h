/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:18:39 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/07 22:25:02 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "libft.h"

typedef struct		s_color_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color_rgb;

typedef struct		s_color_hsv
{
	unsigned short	h;
	unsigned char	s;
	unsigned char	v;
}					t_color_hsv;

typedef struct		s_color_hsl
{
	unsigned short	h;
	unsigned char	s;
	unsigned char	l;
}					t_color_hsl;

t_color_rgb			ft_color_rgb(unsigned char r, unsigned char g
		, unsigned char b);

t_color_hsv			ft_color_hsv(unsigned short h, unsigned char s
		, unsigned char v);

t_color_hsl			ft_color_hsl(unsigned short h, unsigned char s
		, unsigned char l);

t_color_rgb			ft_color_hsv_to_rgb(t_color_hsv hsv);

#endif
