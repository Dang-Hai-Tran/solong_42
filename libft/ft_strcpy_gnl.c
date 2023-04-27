/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:08:49 by datran            #+#    #+#             */
/*   Updated: 2023/03/18 22:26:00 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strcpy_gnl(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		(dst)[i] = (src)[i];
		i++;
	}
	(dst)[i] = '\0';
	return (dst);
}
