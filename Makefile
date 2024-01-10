# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2024/01/10 10:21:17 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= 	fractol
CC 			= 	gcc
CFLAGS 		= 	-Wall -Werror -Wextra -Imlx
# LIBFT_DIR 	= 	libft
MAKEFLAGS 	+=	 --no-print-directory
.SILENT:

# Colors

DEF_COLOR 	= 	\033[0;39m
GRAY 		= 	\033[0;90m
RED 		= 	\033[0;91m
GREEN 		=	\033[0;92m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m
MAGENTA 	=	\033[0;95m
CYAN 		= 	\033[0;96m
WHITE 		= 	\033[0;97m

# Sources

SRC_FILES 	= 	main
SRC 		=	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(SRC:.c=.o)

###

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)fract-ol compiled!$(DEF_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# libft:
# 	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@echo "$(BLUE)fract-ol object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)fract-ol executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for fract-ol!$(DEF_COLOR)"

norm:
	@norminette $(SRC) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm