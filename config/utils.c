/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:23:44 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/10 16:58:47 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	is_validchr(char s)
{
	if (s && \
		(s != ' ' || (s < '0' && s > '2')))
		return (0);
	return (1);
}

int	skip_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

int	skip_space(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] == ' ')
		i++;
	return (i);
}

int	setclr(char *s, int *p_i, int *p_j, int *nbr)
{
	int	tmp;
	int	i;
	int	j;

	i = *p_i;
	j = *p_j;
	i += skip_space(&s[i]);
	tmp = ft_atoi(&s[i]);
	if ((s[i] && !ft_isdigit(s[i]) && s[i] != ' ') || tmp > 255)
		return (-2);
	i += skip_digit(&s[i]);
	if (s[i] == ',')
		i++;
	*nbr |= tmp << j;
	j -= 8;
	*p_i = i;
	*p_j = j;
	return (0);
}

int	chkarnd(char **map, int max, int h, t_itdar it)
{
	const char	*s = "012WSEN";
	int			i;
	int			j;

	i = it.i;
	j = it.j;
	if ((j < max - 1 && !ft_strchr(s, map[i][j + 1])) || \
		(j && !ft_strchr(s, map[i][j - 1])) || \
		(i < h && !ft_strchr(s, map[i + 1][j])) || \
		(i && !ft_strchr(s, map[i - 1][j])))
		return (0);
	if (map[i][j] == '0')
	{
		if (i && j && !ft_strchr(s, map[i - 1][j - 1]))
			return (0);
		if (i && j < max - 1 && !ft_strchr(s, map[i - 1][j + 1]))
			return (0);
		if (i < h && j && !ft_strchr(s, map[i + 1][j - 1]))
			return (0);
		if (i < h && j < max - 1 && !ft_strchr(s, map[i + 1][j + 1]))
			return (0);
	}
	return (1);
}
