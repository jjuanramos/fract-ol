# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2024/01/10 16:00:15 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= 	fractol
INCLUDE 	= 	include
CC 			= 	gcc
CFLAGS 		= 	-Wall -Werror -Wextra -I
SRC_DIR 	= 	src/
OBJ_DIR 	= 	obj/
LIBFT_DIR 	= 	libft
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

SRC_FILES 	= 	main complex

SRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF 		=	.cache_exists

###

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(INCLUDE)
	@echo "$(GREEN)fractol compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(BLUE)fractol object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)fractol executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for fractol!$(DEF_COLOR)"

so: $(OBJ)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(LIBFT_DIR) -c $(SRC)
	$(CC) -nostartfiles -shared -o fractol.so $(OBJ) $(LINK_FLAGS)

norm:
	@norminette $(SRC) $(LIBFT_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re so libft norm