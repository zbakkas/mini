/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-27 19:46:29 by zbakkas           #+#    #+#             */
/*   Updated: 2024-06-27 19:46:29 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "min.h"

void	ft_lstiterr(t_args_n *lst, void (*f)(char *, char *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f("cmd",lst->cmd);
        f("flag",lst->flag);
        f("dependes",lst->dependes);
        f("token",lst->token);
        printf("-----------------------\n");
		lst = lst->next;
	}
}

void f(char *name,char *str)
{
    printf("%s==>\033[0;32m%s\033[0m<==\n",name,str);
    
}