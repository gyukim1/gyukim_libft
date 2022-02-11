/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:40:29 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 18:03:02 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//mem함수는 1바이트씩 값을 수정하기때문에 unsigned char
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	//void형식을 unsigned char로 캐스팅 하기위함
	unsigned char	*new_dest;
	unsigned char	*new_src;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)					//dest의 주소 길이가 src주소 길이보다 작은경우 복사해도 문제가 없기에
	{
		new_dest = (unsigned char *)dest;	//
		new_src = (unsigned char *)src;
		while (n--)
			*new_dest++ = *new_src++;	//n사이즈 만큼 복사
	}
	else
	{
		//dest의 주소 길이가 src보다 뒤에있는경우 overlap의 가능성이 있기때문에 뒤에서부터 복사
		new_dest = (unsigned char *)dest + (n - 1);	//n은 배열이 끝나는 부분이라서 n-1부터 복사
		new_src = (unsigned char *)src + (n - 1);
		while (n--)
			*new_dest-- = *new_src--;
	}
	return (dest);
}
