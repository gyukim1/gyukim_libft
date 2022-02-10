/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:44:59 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 17:55:31 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(str);
	if (str == NULL || set == NULL)
		return (0);
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	while (str[end - 1] && ft_strchr(set, str[end - 1]) && end > start)
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(str, start, end - start));
}
