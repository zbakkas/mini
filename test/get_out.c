/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:50:44 by zbakkas           #+#    #+#             */
/*   Updated: 2024/09/04 13:36:14 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

// static int	get_out_count(char **str)
// {
// 	int		x;
// 	int		c;

// 	x = 0;
// 	c = 0;
// 	while (str[x])
// 	{
// 		if ((!ft_strncmp(str[x], ">", 2)
// 				|| !ft_strncmp(str[x], ">>", 3)) )
// 			c++;
// 		x++;
// 	}
// 	return (c);
// }

// static void	get_out_v(t_out	*out, int *c, bool bol, char *str)
// {
// 	out[*c].last = ft_strdup("1");
// 	out[*c].is_am = false;
// 	out[*c].out = str;
// 	out[*c].is_a = bol;
// 	(*c)++;
// }

// t_out	*get_out(char **str)
// {
// 	t_out	*out;
// 	int		x;
// 	int		c;

// 	x = 0;
// 	c = 0;
// 	out = malloc((get_out_count(str) + 1) * sizeof(t_out));
// 	while (str[x])
// 	{
// 		if ((!ft_strncmp(str[x], ">", 2)
// 				|| !ft_strncmp(str[x], ">>", 3)) )
// 		{
// 			if (!ft_strncmp(str[x], ">", 2))
// 				get_out_v(out, &c, false, ft_strdup(str[x + 1]));
// 			else
// 				get_out_v(out, &c, true, ft_strdup(str[x + 1]));
// 		}
// 		x++;
// 	}
// 	out[c].last = NULL;
// 	out[c].is_am = false;
// 	out[c].out = NULL;
// 	out[c].is_a = false;
// 	return (out);
// }
