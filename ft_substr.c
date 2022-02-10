/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:17:37 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 18:07:11 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!str)
		return (0);
	if (ft_strlen(str) < len)
		len = ft_strlen(str);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (len--)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
