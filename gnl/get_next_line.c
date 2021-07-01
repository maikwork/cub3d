/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:11 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/12 09:34:40 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freestr(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

static int	trnopr_i(int w, int y, int n)
{
	if (w)
		return (y);
	return (n);
}

static char	*get_state(char *state)
{
	char	*tmpstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!state)
		return (0);
	while (state[i] && state[i] != '\n')
		i++;
	if (!state[i])
		return (freestr(state));
	tmpstr = malloc(sizeof(char) * ((ft_strlen(state) - i++) + 1));
	if (!tmpstr)
		return (0);
	while (state[i])
		tmpstr[j++] = state[i++];
	tmpstr[j] = '\0';
	freestr(state);
	return (tmpstr);
}

static char	*get_line(char *str)
{
	int		i;
	char	*tmpstr;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	tmpstr = malloc(sizeof(char) * (i + 1));
	if (!tmpstr)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmpstr[i] = str[i];
		i++;
	}
	tmpstr[i] = '\0';
	return (tmpstr);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*state;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!has_line(state) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		state = ft_strjoing(state, buff);
	}
	freestr(buff);
	*line = get_line(state);
	state = get_state(state);
	return (trnopr_i(!reader, 0, 1));
}
