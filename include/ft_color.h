/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:18:39 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/21 19:09:04 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "libft.h"
# include "ft_math.h"

typedef struct		s_color_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color_rgb;

typedef struct		s_color_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			a;
}					t_color_rgba;

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
t_color_rgb			ft_color_rgb_add_rgba(t_color_rgb rgb, t_color_rgba rgba);

t_color_rgba		ft_color_rgba(unsigned char r, unsigned char g
		, unsigned char b, float a);

t_color_rgb			ft_color_interpolate(t_color_rgb a, t_color_rgb b, float v);

t_color_hsv			ft_color_hsv(unsigned short h, unsigned char s
		, unsigned char v);

t_color_hsl			ft_color_hsl(unsigned short h, unsigned char s
		, unsigned char l);

t_color_rgb			ft_color_hsv_to_rgb(t_color_hsv hsv);
t_color_rgb			ft_color_rgba_to_rgb(t_color_rgba rgba);

#endif
