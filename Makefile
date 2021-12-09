NAME = so_long

SRCS = $(wildcard src/*.c)


FLAGS = -Wall -Wextra -Werror

# %.o: %.c
	#  @ $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	# @ $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@



all : $(SRCS)
	@ echo "Compiling for macOs"
	@ $(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@ echo "Cleaning bins..."
	@ rm -rf $(OBJS)
	@ rm -rf $(wildcard *.o)

fclean : clean
	@ echo "Cleaning all..."
	@ rm -rf $(NAME)

re : fclean all