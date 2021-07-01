/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:23:08 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/12 09:23:07 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parser_line(t_conf *conf, char *line)
{
	int			i;
	static int	cntcnf;

	i = skip_space(line);
	if (cntcnf != 9 && !line[i])
		return (2);
	if (line[i] == 'R' && line[i + 1] == ' ')
		return (++cntcnf && prsdsp(conf, &line[i]));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (++cntcnf && prstxturs(conf, &line[i]));
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (++cntcnf && prstxturs(conf, &line[i]));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (++cntcnf && prstxturs(conf, &line[i]));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (++cntcnf && prstxturs(conf, &line[i]));
	else if (line[i] == 'S' && line[i + 1] == ' ')
		return (++cntcnf && prstxturs(conf, &line[i]));
	else if (line[i] == 'F' && line[i + 1] == ' ')
		return (++cntcnf && prsclr(conf, &line[i]));
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (++cntcnf && prsclr(conf, &line[i]));
	else if (cntcnf == 8 || cntcnf == 9)
		return ((cntcnf = 9) && prsmap(conf, line));
	return ((conf->err = -3) && 0);
}

int	srch_h(char *path)
{
	int			fd;
	int			chk;
	char		*line;
	int			chkmap;
	t_chrconf	chrconf;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	init_chrconf(&chrconf);
	chkmap = 0;
	while (get_next_line(fd, &line))
	{
		chk = check_chrcnf(&chrconf, line);
		if (!chk)
			return (0);
		if (chk == 2)
			chkmap--;
		chkmap++;
		free(line);
	}
	free(line);
	close(fd);
	return (check_flcnf(&chrconf) * (chkmap - 7));
}

int	ft_parser(char *path, t_conf *conf)
{
	int		fd;
	char	*line;

	if (!init_conf(conf, path))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ((conf->err = -4) && 0);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!parser_line(conf, line))
			return (0);
		free(line);
	}
	if (!parser_line(conf, line))
		return (0);
	if (!check_map(conf))
		return ((conf->err = -5) && 0);
	free(line);
	close(fd);
	return (1);
}
