/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:19:08 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/26 19:58:36 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <wchar.h>

void	ft_putwstr_fd(wchar_t const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_wstrlen(s) * sizeof(wchar_t));
}
