/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:36:50 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/09 17:50:30 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_s;
	unsigned char	new_c;

	new_s = (unsigned char *)s;
	new_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == new_c)
			return (new_s + i);
		i++;
	}
	return (NULL);
}
