/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:59:27 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/12 17:31:40 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_numlen(long int i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		j++;
	}
	while (i > 0)
	{
		i /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			l;
	int			j;

	nb = (long int) n;
	l = ft_numlen(nb);
	j = -1 ;
	str = (char *)malloc((sizeof(char) * (l + 1)));
	if (!str)
		return (0);
	str[l--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		j = 0;
	}
	while (l > j)
	{
		str[l] = 48 + (nb % 10);
		nb = nb / 10;
		l--;
	}
	return (str);
}
