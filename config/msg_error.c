/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:24:03 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/10 10:45:22 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	msgerr(int err)
{
	char	*msg;

	msg = NULL;
	if (err == -1)
		msg = "Not valid str.\n";
	if (err == -2)
		msg = "Not valid digit.\n";
	if (err == -3)
		msg = "Not valid config.\n";
	if (err == -4)
		msg = "Not valid path.\n";
	if (err == -5)
		msg = "Not valid map.\n";
	if (err == -6)
		msg = "Not valid path config.\n";
	if (err == -7)
		msg = "Not valid command for save.\n";
	if (err == -8)
		msg = "Not valid txturs/sprt.\n";
	write(1, msg, ft_strlen(msg));
	return (1);
}
