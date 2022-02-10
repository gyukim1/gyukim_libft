/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:11:40 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 18:11:42 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length) + 1);
	if (str == 0)
		return (0);
	while (i < length)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
