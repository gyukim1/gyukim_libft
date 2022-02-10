/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:45:48 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 16:52:42 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!substr[i])
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == substr[j] && i + j < len)
		{
			j++;
			if (!substr[j])
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
