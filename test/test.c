
#include "min.h"

int	main(int argc, char **argv, char **envp)
{    
    char **t =(char **)malloc(6*sizeof(char *));
	t[0]="|";
	t[1]="<";
	t[2]="<<";
	t[3]=">>";
	t[4]=">";
	t[5]=NULL;
	t_args args;
	t_args_n *args_n =NULL;
	while (1)
	{
		clear_list(&args_n);
		char	*line = readline(get_str_redline());
		if(line[0])
		{
			get_all(line,t,&args,&args_n);
    		// int i =0;
			// while (args.cmd[i])
			// {
			// 	printf("cmd==>\033[0;32m%s\033[0m<==\n",args.cmd[i]);
			// 	printf("flag==>\033[0;32m%s\033[0m<==\n",args.flag[i]);
			// 	printf("depends==>\033[0;32m%s\033[0m<==\n",args.dependes[i]);
			// 	printf("token==>\033[0;32m%s\033[0m<==\n",args.token[i]);
			// 	printf("-----------------------\n");
			// 	printf("cmd==>\033[0;32m%s\033[0m<==\n",args_n->cmd);
			// 	i++;
			// }
			ft_lstiterr(args_n,f);
		}
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