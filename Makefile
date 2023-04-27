# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: datran <datran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 17:59:52 by datran            #+#    #+#              #
#    Updated: 2023/04/24 15:33:03 by datran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
BONUS		=	so_long_bonus
LIBFT		=	libft/libft.a
MLX			=	mlx/libmlx.a
CC			=	cc

SRCS_DIR	=	srcs/
SRCS_FILES	=	so_long.c movements.c map.c \
				key_manager.c game.c exit.c \
				error.c check_map.c dfs_map.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		=	$(SRCS:%.c=%.o)

BSRCS_DIR	=	srcs_bonus/
BSRCS_FILES	=	so_long_bonus.c movements_bonus.c map_bonus.c \
				key_manager_bonus.c game_bonus.c exit_bonus.c \
				error_bonus.c step_in_enemy_bonus.c check_map_bonus.c dfs_map_bonus.c
BSRCS		=	$(addprefix $(BSRCS_DIR), $(BSRCS_FILES))
BOBJS		=	$(BSRCS:%.c=%.o)

LIBFTFLAGS			=		-Llibft -lft
MLXFLAGS			=		-Lmlx -lmlx -lXext -lX11 -lm -lz


CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:		$(NAME)
bonus:		$(BONUS)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(OBJS) $(CFLAGS) $(LIBFTFLAGS) $(MLXFLAGS) -o $(NAME)

$(BONUS):	$(BOBJS) $(LIBFT) $(MLX)
			$(CC) $(BOBJS) $(CFLAGS) $(LIBFTFLAGS) $(MLXFLAGS) -o $(BONUS)
$(LIBFT):
			make -C libft

$(MLX):
			make -C mlx

clean:
			make -C libft clean
			make -C mlx clean

fclean:		clean
			$(RM) $(NAME) $(BONUS) $(OBJS) $(BOBJS)
			$(RM) $(LIBFT) mlx/libmlx.a mlx/libmlx_Linux.a

re:			fclean all

rebonus:	fclean bonus

git:
			@git add -A
			@git commit -m "$m"
			@git push
			@echo "Commit sent to GitHub"
# Use make git m="msg to commit"

.PHONY:		all clean fclean re bonus rebonus git
