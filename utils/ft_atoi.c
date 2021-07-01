/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:20:51 by rbliss            #+#    #+#             */
/*   Updated: 2021/03/26 15:45:32 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	size_t	num;
	int		minus;

	minus = 1;
	i = 0;
	num = 0;
	while ((str[i] > 8 && str[i] < 16) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
		num = num * 10 + (str[i++] - '0');
	if (num > MAX_LONG)
		return (0);
	if (num)
		return (minus * num);
	return (0);
}
