/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:09:50 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/16 15:16:05 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char *join;
	size_t	len_s1;
	size_t i;

	len_s1 = ft_len(s1);
	join = malloc(len_s1 + ft_len(s2) + 1);
	join[len_s1 + ft_len(s2)] = 0;
	i = 0;
	while (s1 && i < len_s1)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && (i - len_s1) < ft_len(s2))
	{
		join[i] = s2[i - len_s1];
		i++;
	}
	free(s1);
	return (join);
}

char	ft_cleaner(char	*str)
{
	int			nline;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	nline = 0;
	while (str[i])
	{
		if (nline > 0)
		{
			str[j++] = str[i];
		}
		if (str[i] == '\n')
			nline = 1;
		str[i++] = '\0';
	}
	return (nline);
}
