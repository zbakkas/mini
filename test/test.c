
#include "min.h"





int	main(int argc, char **argv, char **envp)
{    
    char **str = NULL;
	t_envp		*env=NULL;///hod
	// t_args args;
	t_args_n *args_n =NULL;

		
		char	*line = ("ls | cr -l $USER $fddv v $");
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



//  printf("%s\n",ft_strnstr("cat t.txt |grep e  > out","|",30));
	
	
}

// int main()
// {
//     char * str="cat text.txt | grep \"e\" > out";
//     char *ss =strdup("ls");
//     get_all(ss);
// }