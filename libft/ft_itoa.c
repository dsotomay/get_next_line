/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 00:42:01 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/06 00:42:03 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numcount(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		i++;
		return (i);
	}
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		++i;
		n /= 10;
	}
	return (i);
}

static void		ft_renum(char *str, int n, int i)
{
	size_t	nb;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[0] = '-';
			str[1] = '2';
			nb = 147483648;
		}
		else
		{
			str[0] = '-';
			nb = n * -1;
		}
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_renum(str, nb / 10, --i);
		ft_renum(str, nb % 10, ++i);
	}
	else
		str[i] = (nb + '0');
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(ft_numcount(n))))
		return (NULL);
	ft_renum(str, n, ft_numcount(n) - 1);
	return (str);
}
