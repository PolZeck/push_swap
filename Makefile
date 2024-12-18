# **************************************************************************** #
#                                                                              #
#                              💻 PUSH_SWAP 💻                                 #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = push_swap

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
OPS_DIR = $(SRC_DIR)/operations

# Fichiers sources et objets
SRC =	$(SRC_DIR)/push_swap.c \
    	$(SRC_DIR)/stack_utils.c \
    	$(SRC_DIR)/parse_input.c \
    	$(SRC_DIR)/parse_input_utils.c \
    	$(SRC_DIR)/utils.c \
		$(SRC_DIR)/cost_utils.c \
		$(SRC_DIR)/final_sort.c \
		$(SRC_DIR)/best_move_utils.c \
		$(SRC_DIR)/position_utils.c \
		$(SRC_DIR)/tiny_sort.c \
		$(SRC_DIR)/tiny_sort_utils.c \
    	$(OPS_DIR)/swap.c \
    	$(OPS_DIR)/push.c \
    	$(OPS_DIR)/rotate.c \
     	$(OPS_DIR)/reverse_rotate.c \


# Transformation des chemins sources en objets
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Couleurs
RESET = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m

# Règle principale
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJ)
	@echo "$(CYAN)🔧 Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)✅ Build successful!$(RESET)"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) 
	@echo "$(YELLOW)🛠️  Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

# Nettoyage complet (obj + binaire)
fclean: clean
	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Recompilation complète
re: fclean all

# Vérification de la norme 42
norme:
	@echo "$(CYAN)📏 Checking norme...$(RESET)"
	@norminette $(SRC_DIR) $(OPS_DIR)

# Règle pour exécuter le programme avec des arguments
run: $(NAME)
	@echo "$(CYAN)🚀 Running $(NAME) with arguments '42 23 17 8'...$(RESET)"
	./$(NAME) 42 23 17 8

# Règles phony
.PHONY: all clean fclean re norme run
