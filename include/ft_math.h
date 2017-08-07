/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:17:25 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/07 19:02:01 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"
# include <math.h>

# define MATH_MX_SIZE 4
# define MATH_TO_RAD(deg) (deg * M_PI / 180)
# define MATH_TO_DEG(rad) (rad * 180 / M_PI)

typedef struct	s_vec2i
{
	int		x;
	int		y;
}				t_vec2i;

typedef struct	s_vec3f
{
	float	x;
	float	y;
	float	z;
}				t_vec3f;

typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

typedef struct	s_vec3ld
{
	long double		x;
	long double		y;
	long double		z;
}				t_vec3ld;

typedef struct	s_matrix
{
	float	m[MATH_MX_SIZE * MATH_MX_SIZE];
}				t_matrix;

t_matrix		*ft_matrix_new();
t_matrix		*ft_matrix_copy(t_matrix *dst, t_matrix const *const src);
void			ft_matrix_del(t_matrix **mx);
void			ft_matrix_to_identity(t_matrix *const mx);
void			ft_matrix_multiply(t_matrix *dest, t_matrix const *const a
		, t_matrix const *const b);
void			ft_matrix_translate(t_matrix *mx, float x, float y, float z);
void			ft_matrix_scale(t_matrix *mx, float x, float y, float z);
void			ft_matrix_rot_x(t_matrix *mx, float alpha);
void			ft_matrix_rot_y(t_matrix *mx, float alpha);
void			ft_matrix_rot_z(t_matrix *mx, float alpha);

t_vec3f			ft_vec3f(float x, float y, float z);
t_vec3f			*ft_vec3f_new(float x, float y, float z);
t_vec3f			ft_vec3f_transform(t_vec3f const *const vec
		, t_matrix const *const mx);

t_vec3d			ft_vec3d(double x, double y, double z);
t_vec3d			*ft_vec3d_new(double x, double y, double z);

t_vec3ld		ft_vec3ld(long double x, long double y, long double z);
t_vec3ld		*ft_vec3ld_new(long double x, long double y, long double z);

t_vec2i			ft_vec2i(int x, int y);
t_vec2i			*ft_vec2i_new(int x, int y);

#endif
