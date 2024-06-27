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

t_args	*ft_lstnew_one(char *cmd,char * flag,char *token,char * dependes)
{
	t_args	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->cmd = cmd;
    new_node->flag = flag;
	new_node->token = token;
	new_node->dependes = dependes;
	// new_node->out = out;
	// new_node->next = NULL;
	return (new_node);
}
void	ft_lstadd_backk(t_args **lst, t_args *new)
{
	t_args	*re;

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