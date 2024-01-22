# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juramos <juramos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:43:25 by juramos           #+#    #+#              #
#    Updated: 2024/01/22 17:04:39 by juramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME 		= 	fractol

# Compiler
CC 			= 	gcc
CFLAGS 		= 	-Wall -Werror -Wextra

# Libft
LIBFT_PATH	= 	libft/
LIBFT_NAME	= 	libft.a
LIBFT		= 	$(LIBFT_PATH)$(LIBFT_NAME)

# Mlx
MLX_PATH	= 	mlx/
MLX_NAME	= 	libmlx.a
MLX			= 	$(MLX_PATH)$(MLX_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./mlx

# Sources
SRC_DIR 	= 	src/
SRC_FILES 	= 	fractol initialize utils color render sets events args
SRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

# Objects
OBJ_DIR 	= 	obj/
OBJ 		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

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

# Config
OBJF 		=	.cache_exists
MAKEFLAGS 	+=	--no-print-directory
.SILENT:

###

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(MLX):
	@echo "Making mlx..."
	@make -sC $(MLX_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(INC) -lmlx -framework OpenGL -framework AppKit
	@echo "$(GREEN)fractol compiled!$(DEF_COLOR)"

libft:
	@make -sC $(LIBFT_PATH)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "$(BLUE)fractol object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
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