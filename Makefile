# **************************************************************************** #
#                                💻 PUSH_SWAP 💻                               #
# **************************************************************************** #

# Couleurs pour les messages affichés
RESET   = \033[0m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
CYAN    = \033[1;36m
RED     = \033[1;31m
NC      = \033[0m

# Nom de l'exécutable
NAME = push_swap

# Compilateur et flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
OPS_DIR = $(SRC_DIR)/operations

# Liste des fichiers source
SRC = $(SRC_DIR)/push_swap.c \
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
      $(OPS_DIR)/reverse_rotate.c

# Transformation des chemins sources en objets
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# **************************************************************************** #
#                                REGLES PRINCIPALES                            #
# **************************************************************************** #

# Règle principale : compilation de l'exécutable
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJ)
	@echo "$(CYAN)🔧 Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)✅ Build successful!$(RESET)"

# **************************************************************************** #
#                         COMPILATION DES FICHIERS OBJETS                      #
# **************************************************************************** #

# Compilation des fichiers .c en fichiers .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) 
	@echo "$(YELLOW)🛠️  Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#                                  CLEANUP                                     #
# **************************************************************************** #

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Recompilation complète
re: fclean all

# **************************************************************************** #
#                         VERIFICATION      NORMINETTE                         #
# **************************************************************************** #

norme:
	@echo "$(CYAN)📏 Checking norme...$(RESET)"
	@norminette $(SRC_DIR) $(OPS_DIR)

# **************************************************************************** #
#                                TESTS AVEC PARAMETRES                         #
# **************************************************************************** #

# Exécution des tests avec $(PARAMS) paramètres
test: re
	@echo "$(CYAN)🔍 Running tests with $(PARAMS) parameters...$(RESET)"
	@bash -c ' \
	GREEN="$(GREEN)"; \
	RED="$(RED)"; \
	CYAN="$(CYAN)"; \
	RESET="$(RESET)"; \
	TESTS=250; \
	TOTAL_MOVES=0; \
	PARAM_NB=$(PARAMS); \
	LOG_FILE="result.log"; \
	> $$LOG_FILE; \
	for ((i=1; i<=TESTS; i++)); do \
	    ARG=$$(shuf -i 0-9999 -n $$PARAM_NB); \
	    INSTRUCTIONS=$$(./push_swap $$ARG); \
	    if [ -z "$$INSTRUCTIONS" ]; then \
	        RESULT=$$(echo "" | ./checker_linux $$ARG); \
	        MOVES=0; \
	    else \
	        RESULT=$$(echo "$$INSTRUCTIONS" | ./checker_linux $$ARG); \
	        MOVES=$$(echo "$$INSTRUCTIONS" | wc -l); \
	    fi; \
	    TOTAL_MOVES=$$((TOTAL_MOVES + MOVES)); \
	    if [ "$$RESULT" = "OK" ]; then \
	        echo -e "Test $$i: $$GREEN OK $$RESET | Instructions: $$MOVES"; \
	    else \
	        echo -e "Test $$i: $$RED KO $$RESET | Instructions: $$MOVES"; \
	        { \
	            echo "Test $$i: KO | ARG=$$ARG | Instructions=$$MOVES"; \
	            echo "Instructions générées :"; \
	            echo "$$INSTRUCTIONS"; \
	            echo ""; \
	        } >> $$LOG_FILE; \
	    fi; \
	done; \
	if [ $$TESTS -gt 0 ] && [ $$TOTAL_MOVES -gt 0 ]; then \
	    AVERAGE=$$((TOTAL_MOVES / TESTS)); \
	else \
	    AVERAGE=0; \
	fi; \
	echo -e "\\nAverage instructions for $$TESTS tests: $$CYAN $$AVERAGE $$RESET"; \
	if [ -s $$LOG_FILE ]; then \
	    echo -e "$$RED Some tests failed. Check $$LOG_FILE for details. $$RESET"; \
	else \
	    echo -e "$$GREEN All tests passed! $$RESET"; \
	fi;'

# **************************************************************************** #
#                                REGLES PHONY                                  #
# **************************************************************************** #

.PHONY: all clean fclean re norme test
