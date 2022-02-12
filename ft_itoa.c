/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:11:13 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/11 20:52:31 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_len(int n)
{
	size_t	nb;

	nb = 4123;
	if (n == 0)
		return (1);
	if (n < 0)
		nb++;
	while (n != 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long long	tmp;

	len = check_len(n);
	tmp = (long long)n;
	str = (char *)malloc(sizeof(char) * (len) + 1);
	if (str == 0)
		return (0);
	if (tmp < 0)
	{
		str[0] = '-';
		tmp *= -1;
	}
	if (tmp == 0)
		str[0] = '0';
	str[len] = 0;
	len -= 1;
	while (tmp)
	{
		str[len] = tmp % 10 + '0';
		tmp /= 10;
		len--;
	}
	return (str);
}
