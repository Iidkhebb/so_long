NAME = so_long
SRCS = $(wildcard src/*.c)
SRCS_B = $(wildcard bonus/*bonus.c)
CFILES = src/ft_libft.c src/get_next_line.c \
src/get_next_line_utils.c src/is_valid.c src/key_hook.c \
src/logic_handler.c src/map_checker.c src/map_loader.c \
src/nvidia_rtx.c src/so_long.c src/welcome.c
BFILES = bonus/enemy_bonus.c bonus/enemy_logic_bonus.c \
bonus/ft_putstr_bonus.c bonus/ft_strlen2_bonus.c \
bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
bonus/is_valid_bonus.c bonus/key_hook_bonus.c bonus/logic_handler_bonus.c \
bonus/map_checker_bonus.c bonus/map_loader_bonus.c bonus/nvidia_rtx_bonus.c \
bonus/put_text_img_bonus.c bonus/so_long_bonus.c bonus/welcome_bonus.c

FLAGS = -Wall -Wextra -Werror

all : $(CFILES)
	@ echo "Compiling Mandatory...."
	$(CC) $(CFILES) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus : $(SRCS_B)
	@ echo "Compiling Bonus...."
	$(CC) $(SRCS_B) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean :
	@ echo "Cleaning..."
	@ rm -rf $(OBJS)
	@ rm -rf $(wildcard *.o)
fclean : clean
	@ echo "Cleaning all..."
	@ rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re bonus
