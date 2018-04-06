/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 00:08:00 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/03 00:08:08 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	char *tmp;

	i = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	tmp = (char*)s1;
	ft_strcpy(str, s1);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	ft_strcat(str, s2);
	free(tmp);
	//free(s2);
	return (str);
}
