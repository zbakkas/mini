
#include "min.h"

int	main(int argc, char **argv, char **envp)
{    
    char **t =(char **)malloc(6*sizeof(char *));
	t[0]="|";
	t[1]="<";
	t[2]="<<";
	t[3]=">>";
	t[4]=">";
	t_args args;
	while (1)
	{
		char	*line = readline(get_str_redline());
		char * str =ft_strdup(line);
		
        // printf("%s\n",str);
		get_all(line,t,&args);
    	int i =0;
		while (args.cmd[i])
		{
			printf("cmd==>%s<-\n",args.cmd[i]);
			printf("flag==>%s<-\n",args.flag[i]);
			printf("depends==>%s<-\n",args.dependes[i]);
			printf("token==>%s<-\n",args.token[i]);
			i++;
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