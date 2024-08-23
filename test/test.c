
#include "min.h"
# include <signal.h>
// #include <sys/wait.h>


int g_exit_status =115;

void signal_handler(int signal)
{
    if (signal == SIGINT) {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
		/// g_exit_status 130;
    }
}

void ll()
{
	system("leaks mini");
}

int	main(int argc, char **argv, char **envp)
{    
    char **str = NULL;
	t_envp		*env=NULL;///hod
	// t_args args;
	t_args_n *args_n =NULL;
	atexit(ll);

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
		while (1)
		{
			char	*line = readline("$ ");
			if(!line)
				exit(1);
			args_n =initialization_list(line,envp);
			ft_lstiterr(args_n);
			clear_list(&args_n);
			
			free(line);
		// free_to_pin(str);  
		}

//  printf("%s\n",ft_strnstr("cat t.txt |grep e  > out","|",30));
	
	
}

// int main()
// {
//     char * str="cat text.txt | grep \"e\" > out";
//     char *ss =strdup("ls");
//     get_all(ss);
// }