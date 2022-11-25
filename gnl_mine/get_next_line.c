/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:54:12 by ohassnao          #+#    #+#             */
/*   Updated: 2022/11/25 15:51:13 by ohassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			val_ret;
	static char	*stach;
	int			index_nl;
	char		*line;

	val_ret = read(fd, buff, BUFFER_SIZE);
	if (!stach)
		stach = ft_strdup("");
	while (val_ret >= 0)
	{
		buff[val_ret] = '\0';
		stach = ft_strjoin(stach, buff);
		index_nl = check_new_l(stach);
				printf("\n%d\n||",val_ret);
		for (int i = 0; i < BUFFER_SIZE; i++)
				printf("%c",buff[i]);
				printf("||\n");
		if (index_nl != -1)
			return (extract_line(stach, line, index_nl));
		if (!val_ret && stach[0])
			break ;
		if (!val_ret)
			return (after_newline(stach, 0));
		val_ret = read(fd, buff, BUFFER_SIZE);
	}
	free(stach);
	stach = NULL;
	return (NULL);
}

int	check_new_l(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
			i++;
	}
	return (-1);
}

char	*extract_line(char *stach, char *line, int index_nl)
{
	line = ft_substr(stach, 0, index_nl + 1);
	stach = after_newline(stach, index_nl + 1);
	return (line);
}

char	*after_newline(char *stach, int index_nl)
{
	char	*str_afternl;
	int		len;

	len = ft_strlen(stach + index_nl);
	str_afternl = ft_substr(stach, index_nl + 1, len);
		printf("\nstach = %s\n", str_afternl);
	free(stach);
	stach = NULL;
	return (str_afternl);
}
