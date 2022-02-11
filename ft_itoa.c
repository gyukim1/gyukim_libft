/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:11:13 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 18:11:15 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_length(int n)
{
	size_t	nb;

	nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)			//부호체크
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
	size_t		length;
	long long	value;

	length = check_length(n);				//int형 변수의 길이 체크, 동적할당할때 얼만큼의 길이가 필요한지 확인하기위해
	value = (long long)n;					//n의 값을 long long형식으로 캐스팅, 부호변경시 max, min값 overflow피하기 위함
	str = (char *)malloc(sizeof(char) * (length) + 1);
	if (str == 0)
		return (0);
	if (value < 0)				//음수인경우 부호제거
	{
		str[0] = '-';
		value *= -1;
	}
	if (value == 0)				//0인경우 리턴값을 0으로
		str[0] = '0';
	str[length] = 0;			//마지막 자리를 0으로 만들어준후
	length -= 1;				
	while (value)				//값이 0이될때까지 반복
	{
		str[length] = value % 10 + '0';	//마지막자리의 값을 차례대로 뒤에서부터 넣어줌
		value /= 10;			//한자리 앞으로 이동
		length--;			//배열의 인덱스도 이동
	}
	return (str);
}
