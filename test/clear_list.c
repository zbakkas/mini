


#include "min.h"


void	clear_list(t_args_n **lst)
{
	t_args_n	*nexttte;
    int i =0;
	if (!lst)
		return ;
	while (*lst)
	{
        i =0;
		nexttte = (*lst)->next;
        free((*lst)->cmd);
        free((*lst)->arguments);
        while ((*lst)->flags[i])
        {
            free((*lst)->flags[i++]);
        }
        free((*lst)->flags);
		free(*lst);
		*lst = nexttte;
	}
	*lst = NULL;
}
