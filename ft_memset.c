/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:18:16 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 18:05:14 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, unsigned int num)
{
	unsigned char	data;
	unsigned char	*start_ptr;

	start_ptr = (unsigned char *)ptr;
	data = (unsigned char)value;
	while (num-- > 0)
		*start_ptr++ = data;
	return (ptr);
}
