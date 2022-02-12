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

static char	**ft_do_free(char **s)
{
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static char	**ft_do_split(char **str, char const *s, char c, size_t cnt)
{
	size_t	i;
	size_t	j;
	size_t	next;

	i = 0;
	j = 0;
	while (s[i] && j < cnt)
	{
		if (s[i] != c)
		{
			next = i + 1;
			while (s[next] && s[next] != c)
				next++;
			str[j] = ft_substr(s, i, next - i);
			if (!str[j])
				return (ft_do_free(str));
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
		if (s[i] != c)
		{
			cnt++;
			while ((s[i] != c) && s[i])
				i++;
		}
		else
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
	word_cnt = ft_word_cnt(s, c);
	str = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!str)
		return (NULL);
	if (word_cnt == 0)
	{
		str[word_cnt] = 0;
		return (str);
	}
	return (ft_do_split(str, s, c, word_cnt));
}
