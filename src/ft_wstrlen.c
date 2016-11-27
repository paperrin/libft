/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:25:54 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/26 19:27:21 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

size_t		ft_wstrlen(const wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
