

#include "min.h"



t_args_n	*ft_lstnew_one(char *str)
{
	t_args_n	*new_node;

	new_node = malloc(sizeof(t_args_n));
	if (!new_node)
		return (NULL);
	new_node->cmd = get_cmd(str);
    new_node->flags = get_flages(str);
	new_node->arguments = get_argumants(str);
	// new_node->dependes = args.dependes[i];
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