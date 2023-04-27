/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:40:40 by datran            #+#    #+#             */
/*   Updated: 2023/03/30 16:44:56 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_line(char *backup)
{
	int	i;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_backup(char *backup)
{
	int		i;
	int		j;
	char	*newbackup;

	i = 0;
	j = 0;
	if (!backup)
		return (0);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == 0)
	{
		free(backup);
		return (0);
	}
	newbackup = malloc((ft_strlen(backup) - i + 1) * sizeof(char));
	if (!newbackup)
		return (0);
	i++;
	while (backup[i] != '\0')
		newbackup[j++] = backup[i++];
	newbackup[j] = '\0';
	free(backup);
	return (newbackup);
}

int	ft_gnl(int fd, char **line)
{
	static char	*backup;
	char		*buffer;
	int			buffsize;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffsize = 1;
	while (((is_line(backup)) == 0) && (buffsize != 0))
	{
		buffsize = read(fd, buffer, BUFFER_SIZE);
		buffer[buffsize] = '\0';
		backup = ft_strjoin_gnl(backup, buffer);
	}
	free(buffer);
	*line = get_line(backup);
	backup = get_backup(backup);
	if (buffsize == 0)
	{
		free(*line);
		return (0);
	}
	return (1);
}
