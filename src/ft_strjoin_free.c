/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:53:20 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/26 19:46:39 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char **a, char **b, int free)
{
	char	*str;

	str = ft_strjoin(*a, *b);
	if (free == 2 || free == 0)
		ft_strdel(a);
	if (free == 2 || free == 1)
		ft_strdel(b);
	return (str);
}
