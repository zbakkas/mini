

#include "min.h"



void	ft_lstiterr(t_args_n *lst, void (*f)(char *, char *))
{
	if (!lst || !f)
		return ;
        int i =0;
	while (lst)
	{
        i =0;
		f("cmd",lst->cmd);
        while (lst->flags[i])
        {
            f("flag",lst->flags[i++]);
        }
        
        f("arguments",lst->arguments);
        printf("-----------------------\n");
		lst = lst->next;
	}
}

void f(char *name,char *str)
{
    printf("%s==>\033[0;32m%s\033[0m<==\n",name,str);
    
}