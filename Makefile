
NAME		=	so_long

SRCS_FILES	=	${shell find ./src -name "*.c"}

SRCS		=	${SRCS_FILES}
OBJS		=	${SRCS:.c=.o}

LIB_DIR		=	libft
MlX_DIR		=	mlx
INC			=	-I./include -I./libft

CC			=	gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

%.o:			%.c include
						$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
				@make -C $(LIB_DIR)
				@$(CC) $(CFLAGS) $(MLX_FLAGS) $(INC) $(LIB_DIR)/libft.a $(OBJS) -o $(NAME)
				@clear

clean:
				@make clean -C $(LIB_DIR)
				$(RM) $(OBJS)

fclean:		clean
					@make fclean -C $(LIB_DIR)
					$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re