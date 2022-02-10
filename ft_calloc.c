/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:06:29 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 17:09:10 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*res;

	res = (void *)malloc(cnt * size);
	if (!res)
		return (NULL);
	ft_bzero(res, cnt * size);
	return (res);
}
