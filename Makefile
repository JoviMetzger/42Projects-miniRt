# Executable
NAME 			= miniRT
INPUT_FILE		= ./images_rt/test1.rt

# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra
CFLAGS			+= -Werror
# CFLAGS			+= -g -fsanitize=address	# For leaks OR 'make && valgrind --leak-check=full ./miniRT ...'

# Libraries
LIBFT_PATH		= ./libraries/libft
LIBFT 			= $(LIBFT_PATH)/libft.a

MLX42_HEADER	= -I include -lglfw -I $(MLX42_PATH)/include/MLX42/
MLX42_PATH		= ./libraries/mlx42
MLX42			= $(MLX42_PATH)/build/libmlx42.a

# Sources files
SRC_HEADER		= ./header
SRC				= ./src/main.c \
					./src/movement.c \
					./src/open_window.c \
					./src/parse_input.c \
					./src/render.c \
					./src/ray.c \
					./src/colour.c \
					./src/vector.c \
					./src/vec_operators.c \
					./src/

# Objects files
OBJ_PATH		= obj
OBJ				= $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

# Colours
PINK 			= \033[35m
BLUE			= \033[34;1m
GREEN			= \033[32;1m
CORAL			= \033[38;2;255;127;80m
BOLD			= \033[1m
ITALIC			= \033[3m
UNDER 			= \033[4m
RESET			= \033[0m

# Targets
all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX42) $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) $(MLX42_HEADER) -lm -I $(SRC_HEADER) -o $(NAME)
		@echo "$(CORAL) $(UNDER) $(BOLD) $(ITALIC)   ✨Compilation Done✨      $(RESET)"

$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH)
		@echo "$(BLUE)$(BOLD) --- Compiling Libft Done --- $(RESET)"

$(MLX42):
		@cd	$(MLX42_PATH) && cmake -B build && cmake --build build -j4
		@echo "$(BLUE)$(BOLD) --- Compiling Minilibx Done --- $(RESET)"

$(OBJ_PATH)/%.o: ./src/%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAGS) -c -o $@ $<

# ADD LIKE THIS LATER OTHER FOLDERS
# $(OBJ_PATH)/%.o: ./src/utils/%.c
# 		$(CC) $(CFLAGS) -c -o $@ $<

# Executest the program
open: $(NAME)
		@echo "$(PINK)$(BOLD) Opening Window... $(RESET)"
		@./$(NAME) $(INPUT_FILE)
		@echo "$(PINK)$(BOLD) Window Closed $(RESET)"

# Clean
clean:
		@$(MAKE) clean -C $(LIBFT_PATH)
		@rm -rf $(MLX42_PATH)/build
		@rm -rf $(OBJ_PATH)
		@echo "$(GREEN) $(ITALIC) ✅ Cleaned object files ✅$(RESET)"

fclean: clean
		@$(MAKE) fclean -C $(LIBFT_PATH)
		@rm -rf $(NAME)
		@echo "$(GREEN) $(ITALIC)   ✅ Cleaned executer ✅$(RESET)"

re:	fclean all

.PHONY:	all clean fclean re open
