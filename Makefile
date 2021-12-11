NAME = so_long
SRCS = $(wildcard src/*.c)
SRCS_B = $(wildcard bonus/*bonus.c)

FLAGS = -Wall -Wextra -Werror

all : $(SRCS)
	@ echo "Compiling Mandatory...."
	@$(CC) $(SRCS) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus : $(SRCS_B)
	@ echo "Compiling Bonus...."
	$(CC) $(SRCS_B) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean :
	@ echo "Cleaning..."
	@ rm -rf $(OBJS)
	@ rm -rf $(wildcard *.o)
fclean : clean
	@ echo "Cleaning all..."
	@ rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re bonus