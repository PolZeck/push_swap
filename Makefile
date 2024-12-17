# Nom de l'exécutable
NAME = push_swap

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Dossiers
SRC_DIR = src
OBJ_DIR = obj

# Fichiers sources et objets
SRC = $(SRC_DIR)/push_swap.c \
      $(SRC_DIR)/stack_utils.c \
      $(SRC_DIR)/validation.c \
      $(SRC_DIR)/utils.c \
      $(SRC_DIR)/swap.c \
      $(SRC_DIR)/push.c \
      $(SRC_DIR)/rotate.c \
      $(SRC_DIR)/reverse_rotate.c \
      $(SRC_DIR)/algo.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Règle principale
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # Crée le dossier obj s'il n'existe pas
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJ_DIR)

# Nettoyage complet (obj + binaire)
fclean: clean
	@echo "Cleaning all files..."
	rm -f $(NAME)

# Recompilation complète
re: fclean all

# Règles phony
.PHONY: all clean fclean re
