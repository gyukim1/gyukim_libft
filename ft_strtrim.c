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

static int	ft_c_vs_charset(char c, const char *cs)
{
	int	i;

	i = 0;
	while (c != cs[i] && cs[i] && cs[i + 1] != '\0')
		i++;
	if (c == cs[i])
		return (1);
	else
		return (0);
}

static int	ft_quantite_trimer_debut(const char *s, const char *cs)
{	
	int	i;

	i = 0;
	while (s[i] && ft_c_vs_charset(s[i], cs))
		i++;
	return (i);
}

static int	ft_quantite_trimer_fin(const char *s, const char *cs)
{	
	int	i;
	int	len;

	len = ft_strlen(s);
	i = len - 1;
	while (ft_c_vs_charset(s[i], cs) && i > 0)
		i--;
	return (len - (i + 1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		taille;
	int		i;
	int		fin;

	if (!s1)
		return (NULL);
	taille = ft_strlen(s1);
	i = ft_quantite_trimer_debut(s1, set);
	fin = ft_quantite_trimer_fin(s1, set);
	taille = taille - fin - i;
	dst = ft_substr(s1, i, taille);
	return (dst);
}
