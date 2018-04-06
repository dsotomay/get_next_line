/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:59:42 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/28 22:59:45 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int	ret(char **str, int *i, char **line, char **tmp)
{
	char *temp;


	*tmp = *str;
	(*str || i > 0) ?
		*line = ft_strsub(*tmp, 0, (LEN(*tmp) - LEN(ft_strchr(*tmp, '\n')))) :
		(*line = *str);
	temp = *str;
	if (!ft_strchr(*str, '\n'))
		(*str = ft_strjoin(*str, "\n"));
	*str += (LEN(*str) - LEN(ft_strchr(*str, '\n') + 1));
	if (*(*str - 1) != '\n' || ((*(*str - 1) != '\n') && !**str))
	{
		//free(tmp);
		return (0);
	}
	if (temp == '\0')
		free(temp);
	//free(tmp);
	return (1);
}

static int	read_to_buff(char **str, const int fd, char **tmp, char **hold)
{
	int		i;
	char	*temp;

	while (!ft_strchr(*str, '\n'))
	{
		if ((i = read(fd, *tmp, BUFF_SIZE)) < 0)
		{
			free(tmp);
			free(temp);
			return (-1);
		}
		if (i == 0)
		{
//			if (tmp == '\0')
//				free(tmp);
			free(temp);
			break;
		}
		temp = *str;
		*str = ft_strjoin(*str, *tmp);
		*hold = *str;
		*tmp += BUFF_SIZE;
	}
	if (tmp == '\0')
		free(tmp);
	if (temp == '\0')
		free(temp);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static char *str[4242];
	char		*tmp;
	char		*hold;
	int			i;

	if (!(tmp = ft_strnew(sizeof(char*) * (BUFF_SIZE + 1))) || !str[fd])
		if (!(str[fd] = (char*)malloc(sizeof(str[fd]))) || !line || fd < 0
		|| BUFF_SIZE < 0)
		{
			free(tmp);
			if (str[fd] == '\0')
				free(str[fd]);
			return (-1);
		}
	if (ft_strchr(str[fd], '\n'))
	{
		if (str[fd] == '\0')
			free(str[fd]);
		free(tmp);
		return (ret(&str[fd], &i, &*line, &hold));
	}
	if ((i = read_to_buff(&str[fd], fd, &tmp, &hold)) < 0)
	{
		free(str[fd]);
		free(tmp);
		return (-1);
	}
	(*tmp || i > 0) ?
		*line = ft_strsub(hold, 0, (LEN(hold) - LEN(ft_strchr(hold, '\n')))) :
		(*line = str[fd]);
	if (!ft_strchr(str[fd], '\n'))
		(str[fd] = ft_strjoin(str[fd], "\n"));
	str[fd] += (LEN(str[fd]) - LEN(ft_strchr(str[fd], '\n') + 1));
	if (*(str[fd] - 1) != '\n' || ((*(str[fd] - 1) != '\n') && !*str[fd]))
		return (0);
	//free(tmp);
	//free(hold);
	if ((*(str[fd] - 1) != '\n') && *(str[fd]) == '\0')
		free(str[fd]);
	return (1);
}
