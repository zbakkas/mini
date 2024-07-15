
#include "min.h"



void    creat_list(t_envp **envp, char *line)
{
	t_envp   *ptr;
	t_envp   *new_env;

	if (!envp)
		return ;
	new_env = (t_envp *)malloc(sizeof(t_envp));
	if (!new_env)
		return ;
	new_env->env = ft_strdup(line);
	new_env->next = NULL;
	if (!*envp)
	{
		*envp = new_env;
		(*envp)->prev = NULL;
		return ;
	}
	ptr = *envp;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_env;
	new_env->prev = ptr; 
}

void	parsing_env(t_envp **env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		creat_list(env, envp[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{    
    char **str = NULL;
	t_envp		*env=NULL;///hod
	// t_args args;
	t_args_n *args_n =NULL;
	parsing_env(&env, envp);
	while (1)
	{
		
		char	*line = readline(get_str_redline());
		if(line[0])
		{
			args_n =initialization_list(line,env);
			// chake_error(args_n);
			// str = ft_split_pip(line,'|');
			// int  i =0;
			// while (str[i])
			// {
			// 	printf("%d,%s\n",i,str[i]);
			// 	ft_lstadd_backk(&args_n,ft_lstnew_one(str[i++]));
				
			// }
			ft_lstiterr(args_n);
			clear_list(&args_n);
			// char *user = getenv("ARG");
			// printf("%s\n",user);
			// printf("%s\n",args_n->next->flags[i]);
		}
		// free_to_pin(str);
		if (!strcmp(line, "exit"))
			exit(0);
		
	}


//  printf("%s\n",ft_strnstr("cat t.txt |grep e  > out","|",30));
	
	
}

// int main()
// {
//     char * str="cat text.txt | grep \"e\" > out";
//     char *ss =strdup("ls");
//     get_all(ss);
// }