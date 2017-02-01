/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:36:53 by wdebs             #+#    #+#             */
/*   Updated: 2016/11/17 21:53:03 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_realloc(char *str, int start)
{
	char	*temp;

	temp = ft_strdup(str + start);
	free(str);
	return (temp);
}

int		set_extra(char **tmp, char **extra)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (extra && *extra && **extra && ft_strchr(*extra, '\n') != 0)
	{
		while ((*extra)[i] != '\n' && (*extra)[i] != '\0')
			i++;
		*tmp = ft_strnew(i);
		while (++j < i)
			(*tmp)[j] = (*extra)[j];
		if ((*extra)[i] == '\n')
			i++;
		*extra = gnl_realloc(*extra, i);
		return (1);
	}
	else if (extra && *extra && **extra)
	{
		*tmp = ft_strdup(*extra);
		*extra = NULL;
	}
	return (0);
}

char	*fill_extra(char *extra, char *buf, char **tmp)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(buf);
	str = ft_strnew(len);
	i = -1;
	while (buf[++i] != '\n' && buf[i] != '\0')
		str[i] = buf[i];
	if (*tmp != NULL)
		*tmp = ft_strjoin(*tmp, str);
	else
		*tmp = ft_strdup(str);
	free(str);
	if (buf[i] == '\n')
		i++;
	extra = gnl_realloc(buf, i);
	return (extra);
}

int		set_tmp(char **tmp, const int fd, char **buff)
{
	int		i;
	int		ret;
	char	*str;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		str = ft_strnew(ret);
		i = -1;
		while (++i < ret)
			str[i] = buf[i];
		if (ft_strchr(buf, '\n') != 0 || ret < BUFF_SIZE)
		{
			*buff = gnl_realloc(str, 0);
			return (1);
		}
		if (*tmp == NULL)
			*tmp = gnl_realloc(str, 0);
		else
			*tmp = ft_strjoin(*tmp, str);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*extra;
	char		*tmp;
	char		*buf;
	int			check;
	int			ret;

	check = 0;
	tmp = NULL;
	ret = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (extra != NULL && set_extra(&tmp, &extra) != 0)
		check++;
	if (check == 0 && (ret = set_tmp(&tmp, fd, &buf)) == 0)
		check++;
	if (ret < 0)
		return (-1);
	if (check == 0)
		extra = fill_extra(extra, buf, &tmp);
	if (ret == 0 && tmp != NULL && (*line = ft_strdup(tmp)))
		return (1);
	if (ret == 0 && (*line = ft_strnew(1)))
		return (0);
	*line = tmp;
	return (1);
}
