/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:37:16 by zbakkas           #+#    #+#             */
/*   Updated: 2024/09/05 10:28:26 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

void	remove_file(t_files *inp);

void	clear_list(t_args_n **lst)
{
	t_args_n	*nexttte;
	int			i;

	if (!lst)
		return ;
	while (*lst)
	{
		i = 0;
		// remove_file((*lst)->inp);
		nexttte = (*lst)->next;
		while ((*lst)->arguments[i])
			free((*lst)->arguments[i++]);
		free((*lst)->arguments);
		i = 0;
		while ((*lst)->inp[i].last)
			free((*lst)->inp[i++].file);
		free((*lst)->inp);
		i = 0;
		free(*lst);
		*lst = nexttte;
	}
	*lst = NULL;
}

char	*strjoin_parsing(char *start, char *buff)
{
	char	*re;
	int		xx;
	int		x;

	x = 0;
	xx = 0;
	if (!start)
	{
		start = malloc(1);
		start[0] = '\0';
	}
	if (!start || !buff)
		return (0);
	re = malloc(ft_strlen(start) + ft_strlen(buff) + 1);
	if (!re)
		return (NULL);
	while (start[x])
		re[xx++] = start[x++];
	x = 0;
	while (buff[x])
		re[xx++] = buff[x++];
	re[xx] = '\0';
	free(start);
	return (re);
}
