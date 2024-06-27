/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-26 22:16:21 by zbakkas           #+#    #+#             */
/*   Updated: 2024-06-26 22:16:21 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

t_args_n	*ft_lstnew_one(t_args args, int i)
{
	t_args_n	*new_node;

	new_node = malloc(sizeof(t_args_n));
	if (!new_node)
		return (NULL);
	new_node->cmd = args.cmd[i];
    new_node->flag = args.flag[i];
	new_node->token = args.token[i];
	new_node->dependes = args.dependes[i];
	// new_node->out = out;
	new_node->next = NULL;
	return (new_node);
}
void	ft_lstadd_backk(t_args_n **lst, t_args_n *new)
{
	t_args_n	*re;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	re = *lst;
	while (re->next)
	{
		re = re->next;
	}
	re->next = new;
	lst = &re;
}

// void	ft_lstnew_tow(t_args **args,char *out)
// {
//     (*args)->out =out;
// }