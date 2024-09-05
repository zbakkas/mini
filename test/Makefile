CC =cc
CFLAGS =#  -Wall -Wextra -Werror
RM = rm -f
NAME = mini
F = -g -fsanitize=address 


SRC =  test.c get_args2.c set_list.c split_args.c split_pip.c  get_in_out.c  clear_list.c  print_list.c change_var.c check_errors.c set_speace_line.c get_files.c get_out.c change_var_one.c change_var_ulit.c check_errors_var.c wildcards.c wildcards_one.c wildcards_tow.c quote.c  



OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(SRC)
	$(CC) $(CFLAGS)  $(SRC) $(F) libft/libft.a -lreadline -L/goinfre/zbakkas/homebrew/opt/readline/lib -I/goinfre/zbakkas/homebrew/opt/readline/include -o $(NAME) 




# %.o:%.c push_swap.h ./bonus/checker_bonus.h
# 	$(CC) $(CFLAGS) -c $< -o $@ 



clean:
	$(RM) *.o 
fclean:clean
	$(RM) $(NAME) 
	
re:fclean all

.PHONY: all  clean fclean re