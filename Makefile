# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 18:47:34 by danielasayu       #+#    #+#              #
#    Updated: 2024/01/20 19:02:13 by danielasayu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### Bonus Flag Definition ####
BONUS_MODE = "false"

#### Source code ####
CLIENT = src/client.c
SERVER = src/server.c

#### Objects ####
CLIENT_OBJ = $(CLIENT:.c=.o)
SERVER_OBJ = $(SERVER:.c=.o)
OBJS = $(CLIENT_OBJ) $(SERVER_OBJ)

#### Definitions ####
PROJECT_NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server

#### Compiler #### 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
INCLUDES = -I./include -I$(LIBFT_DIR)

#### Colors ####
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
WHITE = \033[0;37m
RESET = \033[0m

#### Rules ####
all: $(PROJECT_NAME)

$(PROJECT_NAME):
	@echo "$(YELLOW) ⟦ Compilando Cliente e Servidor ⟧ $(RESET)"
	@make -C $(LIBFT_DIR) --silent
	@make $(CLIENT_NAME)
	@make $(SERVER_NAME)
	@echo "$(GREEN)✓ Cliente e Servidor Compilados $(RESET)"

$(CLIENT_NAME): $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)
	@echo "$(GREEN)$ Cliente Pronto 👌 $(RESET)"

$(SERVER_NAME): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)
	@echo "$(GREEN)$ Servidor Pronto 👌 $(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)✗ Objetos Removidos $(RESET)"

fclean:
	@rm -f $(OBJS)
	@rm -f $(CLIENT_NAME)
	@rm -f $(SERVER_NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@echo "$(RED)✗ Objetos Removidos $(RESET)"
	@echo "$(RED)✗ Executavel $(CLIENT_NAME) Removido $(RESET)"
	@echo "$(RED)✗ Executavel $(SERVER_NAME) Removido $(RESET)"
	@echo "$(RED)✗✗✗✗✗ Removi a porra toda 😎 ✗✗✗✗✗$(RESET)"

test:
	@echo "$(YELLOW) ☆*: .｡. o(≧▽≦)o .｡.:*☆ $(RESET)"
	@echo "$(YELLOW) ⟦ Testando Cliente e Servidor ⟧ $(RESET)"


%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re testss