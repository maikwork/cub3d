/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:57 by rbliss            #+#    #+#             */
/*   Updated: 2021/03/28 12:43:56 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1000

int					get_next_line(int fd, char **line);
int					has_line(char *str);

size_t				ft_strlen(const char *s);

char				*ft_strjoing(const char *s1, const char *s2);

#endif
