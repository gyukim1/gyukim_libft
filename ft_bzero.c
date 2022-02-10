/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:32:20 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 18:02:29 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	unsigned char	*new_dest;
	size_t			i;

	new_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		new_dest[i] = 0;
		i++;
	}
}
