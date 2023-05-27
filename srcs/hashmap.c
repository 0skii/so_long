/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:28:58 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/05/18 11:44:02 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

char	**read_map(char *path)
{
	int		fd;
	char	**line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (read(fd, *line, BUFFER_SIZE) > 0)
	{
		line[i] = get_next_line(fd);
		i++;
	}
}