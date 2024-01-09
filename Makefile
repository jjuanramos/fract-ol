# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2024/01/09 11:15:42 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= 	fractol
CC 			= 	gcc
CFLAGS 		= 	-Wall -Werror -Wextra -I
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

SRC_FILES 	= 	todo
SRC 		=	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(SRC:.c=.o)

###

all: $(NAME)

$(NAME): $(OBJ)
	# @make -C $(LIBFT_DIR)
	# @cp libft/libft.a .
	# @mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

%.o: %.c
        @$(CC) $(CFLAGS) -c $< -o $@

# libft:
# 	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	# @make clean -C $(LIBFT_DIR)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	# @make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
	# @norminette $(SRC) $(LIBFT_DIR) | grep -v Norme -B1 || true
	@norminette $(SRC) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm