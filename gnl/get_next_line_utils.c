/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:23:12 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:25:45 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_tmp;
	unsigned char	*dest_tmp;

	src_tmp = (unsigned char *)src;
	dest_tmp = (unsigned char *)dst;
	if (dest_tmp < src_tmp)
		while (len-- > 0)
			*dest_tmp++ = *src_tmp++;
	if (dest_tmp > src_tmp)
		while (len-- > 0)
			dest_tmp[len] = src_tmp[len];
	return (dst);
}

char	*ft_strjoing(char const *s1, char const *s2)
{
	const int	s1_len = ft_strlen((char *)s1);
	const int	s2_len = ft_strlen((char *)s2);
	const int	save_len = s1_len + s2_len + 1;
	char		*state;

	state = malloc(sizeof(char) * save_len);
	if (!state)
		return (0);
	ft_memmove(state, s1, s1_len);
	ft_memmove(state + s1_len, s2, s2_len);
	state[save_len - 1] = '\0';
	free((char *)s1);
	return (state);
}

int	has_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}
