/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:20:08 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 16:20:47 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	ptr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (s1)
		ft_strcpy_gnl(ptr, s1, len_s1);
	ft_strcpy_gnl(ptr + len_s1, s2, len_s2);
	free(s1);
	return (ptr);
}
