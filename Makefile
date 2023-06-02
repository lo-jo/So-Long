LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

MINILIBX_DIR	=	./mlx_linux
MINILIBX		=	$(MINILIBX_DIR)/libmlx.a

SRCS	=	main.c \
		check_map.c \
		init_game.c \
		init_sprites.c \
		print_map.c \
		read_map.c \
		trigger_game.c \
		exit.c \

OBJS			= 	$(SRCS:.c=.o)

NAME			=	so_long

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJS) 
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR)

$(MINILIBX):
				make -C $(MINILIBX_DIR)

clean:
				make -C $(LIBFT_DIR) clean
				make -C $(MINILIBX_DIR) clean
				$(RM) $(OBJS) $(NAME)

fclean:			clean
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(RM) $(NAME) 

re:				fclean

.PHONY:		all clean fclean libft re