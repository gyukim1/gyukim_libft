/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:10:45 by gyukim            #+#    #+#             */
/*   Updated: 2022/02/10 23:14:50 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**do_free(char **s)
{
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])			//1차원배열 프리
	{
		free(s[i]);		
		i++;
	}
	free(s);			//2차원배열 프리
	s = NULL;
	return (NULL);
}

static char	**do_split(char **str, char const *s, char c, size_t cnt)
{
	size_t	i;
	size_t	j;
	size_t	next;
	//1차원 배열에서 2차원 배열 str로 단어들을 리스트형식으로 만들어주는 과정
	i = 0;		//i는 1차원배열의 몇번째인지
	j = 0;		//j는 2차원배열의 몇번째인지
	while (s[i] && j < cnt)						
	{
		if (s[i] != c)						
		{
			next = i + 1;				//1차원배열에서 i ~ next까지 짜르기 위해 next를 구함
			while (s[next] && s[next] != c)		//1차원배열에서 s가 끝나지않고 구분자가 나오기 전까지 계속 ++
				next++;
			str[j] = ft_substr(s, i, next - i);	//다 구했으면 i ~ next는 한 단어 이기때문에 str[j]로 넣어줌
			if (!str[j])				//동적할당한 2차원배열이 잘못 된경우
				return (do_free(str));		//모든 2차원배열을 free시킴
			j++;
			i = next;				
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

static int	ft_word_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	if (s == 0)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)				//단어의 첫글자인지
		{
			cnt++;				//단어의 첫글자가 나오면 단어를 하나 카운트+1
			while ((s[i] != c) && s[i])	//구분자가 나올때까지 넘기고
				i++;
		}
		else					//구분자가 연속으로 나오는경우도 있으므로 체크하기위함
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	word_cnt;

	if (!s)
		return (NULL);
	word_cnt = ft_word_cnt(s, c);					//c로 몇개를 나눌수있는지 체크
	str = (char **)malloc(sizeof(char *) * (word_cnt + 1));		//2차원 배열(리스트형식) 동적할당
	if (!str)							//동적할당 에러 체크
		return (NULL);
	if (word_cnt == 0)						//나눌수있는 단어가 없는경우
	{
		str[word_cnt] = 0;					//들어온 문자열을 초기화시키고
		return (str);						//리턴
	}
	return (do_split(str, s, c, word_cnt));				//
}
