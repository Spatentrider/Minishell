# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 13:02:52 by marimatt          #+#    #+#              #
#    Updated: 2023/01/10 13:53:08 by mvolpi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRC_MAIN			=	src/main_proc/init_env.c \
						src/main_proc/main.c \
						src/main_proc/split_utils.c \
						src/main_proc/split.c

LIBFT		=	libft/libft.a

CFLAGS		=	-Wall -Werror -Wextra

OBJ_DIR		=	obj

OBJ			=	$(SRC_MAIN:src/main_proc/%.c=$(OBJ_DIR)/main_proc/%.o) \
					

# LINKS		=	-lreadline
# LINKS		=	-lreadline -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include/readline
# LINKS		=	-lreadline -L/usr/local/Cellar/readline/8.2.1/lib -I /usr/local/Cellar/readline/8.2.1/include/readline

READLINE_FLAG			= -lreadline -lcurses
# READLINE_FLAG			= -lreadline -ltinfo
READLINE_DIR			= readline/
READLINE_A				= readline/libhistory.a readline/libreadline.a
READLINE_MAKEFILE		= readline/Makefile
READLINE_MAKE			= @cd readline && make 
READLINE_CONFIGURE		= cd readline && ./configure 
RMREADLINE				= @cd readline && make distclean

BRANCH 		?= $(shell bash -c 'read -p "Branch: " branch; echo $$branch')
COMMIT 		?= $(shell bash -c 'read -p "Commit: " commit; echo $$commit')

GREEN='\033[1;32m'
RED='\033[1;31m'
YELLOW='\033[1;33m'

all:	$(NAME)

clean:
	@echo $(YELLOW)"-Removing minishell object files..."
	@rm -rf $(OBJ_DIR)
	@echo $(RED)"		MINISHELL OBJECT DELETED!!"
	@make -C libft clean

fclean: clean
	@echo $(YELLOW)"-Removing $(NAME)"
	@rm -rf $(NAME)
	@echo $(RED)"		$(NAME) *.a DELETED!!"
	@make -C libft fclean

re: fclean all

rec: re clean

$(OBJ_DIR):
			@mkdir $(OBJ_DIR)
			@mkdir obj/main_proc

$(OBJ_DIR)/main_proc/%.o: src/main_proc/%.c
				@$(CC) $(CFLAGS) -c -g $< -o $@

# $(OBJ_DIR)/builtins/%.o: src/builtins/%.c
# 				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ_DIR) $(OBJ) $(READLINE_MAKEFILE)
			@echo $(YELLOW)"-Making libft..."
			@make -s -C libft
			@echo $(YELLOW)"-Making $(NAME)..."
			@echo $(RED)"-Making readline..."
			@$(READLINE_MAKE)
			@echo $(GREEN)"		Readline created"
			@gcc $(CFLAGS) $(LIBFT) $(READLINE_A) $(READLINE_FLAG) $(OBJ) -o $(NAME)
			@echo $(RED)"  $(NAME) CREATED!!"
			@echo $(GREEN)"		-COMPILED-"

$(READLINE_MAKEFILE):
	$(READLINE_CONFIGURE)

norm:
		@norminette -R CheckForbiddenSourceHeader

add: fclean
		@git add *.c *.h Makefile
		@git status

push: add
	git commit -m $(COMMIT)
	@git push origin $(BRANCH)

clean_all: fclean
	$(RMREADLINE)
	$(RMLIB)

.PHONY: re fclean clean rec all norm
