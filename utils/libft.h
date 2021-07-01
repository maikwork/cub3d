/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:41:46 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/10 10:23:01 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

# define MAX_LONG 9223372036854775807

int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int		ft_isdigit(int c);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		trnopr_i(int w, int y, int n);
void	*trnopr_a(int w, void *y, void *n);

#	endif
