/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-27 20:10:36 by zbakkas           #+#    #+#             */
/*   Updated: 2024-06-27 20:10:36 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "min.h"

void	clear_list(t_args_n **lst)
{
	t_args_n	*nexttte;

	if (!lst)
		return ;
	while (*lst)
	{
		nexttte = (*lst)->next;
        free((*lst)->cmd);
        free((*lst)->flag);
        free((*lst)->token);
        free((*lst)->dependes);
		free(*lst);
		*lst = nexttte;
	}
	*lst = NULL;
}