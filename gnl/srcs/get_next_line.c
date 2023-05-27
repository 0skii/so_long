/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:17:15 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/16 15:37:23 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

char	*get_next_line(int fd)
{
	static char		unloader[BUFFER_SIZE + 1];
	char			*loader;
	int				i;

	i = 0;
	loader = NULL;
	while (unloader[0] || read(fd, unloader, BUFFER_SIZE) > 0)
	{
		loader = ft_join(loader, unloader);
		if (ft_cleaner(unloader) > 0)
			break ;
	}
	return (loader);
}
