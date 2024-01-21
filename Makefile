# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 18:47:34 by danielasayu       #+#    #+#              #
#    Updated: 2024/01/21 15:47:29 by dsayumi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### Bonus Flag Definition ####
BONUS_MODE = "false"

#### Source code ####
CLIENT = src/client.c
SERVER = src/server.c
CLIENT_BONUS = src_bonus/client_bonus.c
SERVER_BONUS = src_bonus/server_bonus.c
#### Objects ####
CLIENT_OBJ = $(CLIENT:.c=.o)
SERVER_OBJ = $(SERVER:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS:.c=.o)
OBJS_BONUS = $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
OBJS = $(CLIENT_OBJ) $(SERVER_OBJ)

#### Definitions ####
PROJECT_NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

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
	@echo "$(YELLOW) ⟦ Compiling Client and Server ⟧ $(RESET)"
	@make -C $(LIBFT_DIR) --silent
	@make $(CLIENT_NAME)
	@make $(SERVER_NAME)
	@echo "$(GREEN)✓ Compiled Client and Server $(RESET)"

$(CLIENT_NAME): $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)
	@echo "$(GREEN)$ Client Ready 👌 $(RESET)"

$(SERVER_NAME): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)
	@echo "$(GREEN)$ Server Ready 👌 $(RESET)"
bonus:
	@if [ $(BONUS_MODE) = "true" ]; then \
		@echo "$(YELLOW) ⟦ Compiling Client and Server ⟧ $(RESET)"
		@make -C $(LIBFT_DIR) --silent
		@make $(CLIENT_BONUS_NAME)
		@make $(SERVER_BONUS_NAME)
		@echo "$(GREEN)✓ Compiled Bonus Client and Server $(RESET)"
	fi

	$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJ)
		@$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_BONUS_OBJ) $(LIBFT) -o $(CLIENT_BONUS_NAME)
		@echo "$(GREEN)$ Client Ready 👌 $(RESET)"
	
	$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJ)
		@$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_BONUS_OBJ) $(LIBFT) -o $(SERVER_BONUS_NAME)
		@echo "$(GREEN)$ Server Ready 👌 $(RESET)"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(RED)✗ Removed Objects $(RESET)"

fclean:
	@rm -f $(OBJS)
	@rm -f $(CLIENT_NAME)
	@rm -f $(SERVER_NAME)
	@rm -f $(OBJS_BONUS)
	@rm -f $(CLIENT_BONUS_NAME)
	@rm -f $(SERVER_BONUS_NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@echo "$(RED)✗ Removed Objects$(RESET)"
	@echo "$(RED)✗ Executable $(CLIENT_NAME) Removed $(RESET)"
	@echo "$(RED)✗ Executable $(SERVER_NAME) Removed $(RESET)"
	@echo "$(RED)✗✗✗✗✗ All removed 😎 ✗✗✗✗✗$(RESET)"

test:
	@echo "$(YELLOW) ☆*: .｡. o(≧▽≦)o .｡.:*☆ $(RESET)"
	@echo "$(YELLOW) ⟦ Test Client and Server ⟧ $(RESET)"


%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re test bonus