/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reserve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 01:04:59 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/29 17:30:59 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

static void		set_new_meta(t_array *old, t_array *new
	, size_t reserve_front, size_t reserve_back)
{
	*new = (t_array){
		.data = new->data,
		.begin = &new->data[reserve_front],
		.end = &new->data[reserve_front + old->size - 1],
		.f_free = old->f_free,
		.size = old->size,
		.reserve_front = reserve_front,
		.reserve_back = reserve_back
	};
}

t_array_it		ft_array_reserve(t_array *array
	, size_t reserve_front, size_t reserve_back)
{
	t_array		new;
	size_t		i;

	reserve_front = MAX(reserve_front, array->reserve_front);
	reserve_back = MAX(reserve_back, array->reserve_back);
	if (reserve_front <= array->reserve_front
		&& reserve_back <= array->reserve_back)
		return (array->begin);
	new.data = (void**)malloc(sizeof(void*)
		* (array->size + reserve_front + reserve_back));
	if (array->data && !new.data)
		return (NULL);
	set_new_meta(array, &new, reserve_front, reserve_back);
	i = 0;
	while (i < array->size)
	{
		new.data[new.reserve_front + i] = array->data[array->reserve_front + i];
		i++;
	}
	ft_array_free(array);
	*array = new;
	return (array->begin);
}
