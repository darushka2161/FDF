/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choyda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:51:45 by choyda            #+#    #+#             */
/*   Updated: 2022/04/27 13:51:47 by choyda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n, int minus)
{
	int	numlen;

	numlen = 1;
	n /= 10;
	while (n)
	{
		numlen++;
		n /= 10;
	}
	return (numlen + minus);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;
	int		minus;
	int		digit;

	minus = 0;
	if (n < 0)
		minus = 1;
	numlen = ft_numlen(n, minus);
	str = ft_strnew(numlen);
	if (str)
	{
		str[numlen--] = '\0';
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = ft_abs(digit) + '0';
			n /= 10;
		}
		if (minus)
			str[0] = '-';
	}
	return (str);
}
