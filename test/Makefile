CC =cc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -f
NAME = mini


SRC =  test.c get_args2.c set_list.c split_args.c split_pip.c   clear_list.c get_env_realine.c print_list.c change_var.c



OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) libft/libft.a -lreadline -fsanitize=address  -o $(NAME) 




# %.o:%.c push_swap.h ./bonus/checker_bonus.h
# 	$(CC) $(CFLAGS) -c $< -o $@ 



clean:
	$(RM) *.o 
fclean:clean
	$(RM) $(NAME) 
	
re:fclean all

.PHONY: all  clean fclean re