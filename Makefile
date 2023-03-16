NAME := minishell

SRC						=	src/main.c \
							src/reset.c

SRC_ARR					=	src/arr_utils/arr_add_back.c

SRC_BUILTINS			=	src/builtins/builtins.c

SRC_CD					=	src/builtins/cd/cd.c

SRC_ECHO				=	src/builtins/echo/echo.c

SRC_ENV					=	src/builtins/env/env.c

SRC_EXIT				=	src/builtins/exit/exit.c

SRC_EXPORT				=	src/builtins/export/export.c

SRC_PWD					=	src/builtins/pwd/pwd.c

SRC_UNSET				=	src/builtins/unset/unset.c

SRC_CMD					=	src/commands/commands.c \
							src/commands/cmd_utils.c

SRC_EXPANSION			=	src/expansion/expansion.c

SRC_GET_ENV				=	src/get_env/init_env.c

SRC_OPERATOR			=	src/operator/check_op.c \
								src/operator/clean_quote.c \
								src/operator/delete.c \
								src/operator/redirection.c \
								src/operator/utils.c

SRC_PARSE				=	src/parse/parse_utils.c \
							src/parse/parse.c

SRC_PIPE				=	src/pipe/pipe.c \
							src/pipe/pipe_utils.c

SRC_SIGNALS				=	src/signals/signals.c

SRC_SPLIT				=	src/split/split_executor.c \
								src/split/split_parse_quote.c \
								src/split/split_parse_utils.c \
								src/split/split_parse.c \
								src/split/split_pipe.c \
								src/split/split_red.c

FLAGS				:= -g -Wall -Wextra -Werror -fcommon

OBJS				= $(addprefix $(OBJS_DIR)/, ${SRC:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_ARR:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_BUILTINS:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_CD:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_ECHO:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_ENV:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_EXIT:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_EXPORT:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_PWD:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_UNSET:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_CMD:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_EXPANSION:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_GET_ENV:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_OPERATOR:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_PARSE:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_PIPE:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_SPLIT:.c=.o}) \
						$(addprefix $(OBJS_DIR)/, ${SRC_SIGNALS:.c=.o}) 

OBJS_DIR			= objs

READLINE_FLAG	:= -lreadline -lcurses
# READLINE_FLAG	:= -lreadline -ltinfo
READLINE_DIR		:= readline/
READLINE_A			= readline/libhistory.a readline/libreadline.a
READLINE_MAKEFILE 	:= readline/Makefile
READLINE_CONFIGURE	:= @cd readline && sh ./configure
READLINE_MAKE		:= @cd readline && make
RMREADLINE			:= @cd readline && make distclean

LIBFT_DIR	:= libft/
LIBFT_A		:= libft/libft.a
LIBFT_MAKE	:= @cd libft && make && make clean
RMLIB		:= @cd libft && make fclean

CC	= @gcc

DEBUG_F	= -g -fsanitize=address

GREEN='\033[1;32m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
PURPLE='\033[1;35m'
RED='\033[1;31m'
YELLOW='\033[1;33m'

$(NAME): $(OBJS) $(READLINE_MAKEFILE)
	@echo $(PURPLE)"	-Making Readline..."
	@$(READLINE_MAKE) 
	@echo $(GREEN)"		-READLINE COMPILED"
	@echo $(CYAN)"		-Making libft.."
	@$(LIBFT_MAKE)
	@echo $(GREEN)"		-LIBFT COMPILED"
	@echo $(YELLOW)"		-Making $(NAME)..."
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) $(READLINE_A) $(READLINE_FLAG) -o $(NAME) > /dev/null
	@echo $(GREEN)"		-MINISHELL COMPILED"

$(shell echo $(OBJS_DIR))/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(READLINE_MAKEFILE):
	@echo $(BLUE)"		-Readline Configuration..."
	@$(READLINE_CONFIGURE)
	@echo $(GREEN)"		-READLINE CONFIGURED-"

all: $(NAME)

clean:
	@echo $(CYAN)"		Removing minishell objs files..."
	@rm   -rf ${OBJS_DIR}
	@echo $(GREEN)"		-MINISHELL OBJS DELETED"

fclean: clean
	@echo $(RED)"		Removing $(NAME)..."
	@rm -rf ${NAME}
	@echo $(BLUE)"		*.a'S DELETED"
	$(RMLIB)

clean_all: fclean
	$(RMREADLINE)
	$(RMLIB)

readline:	$(READLINE_MAKEFILE)

norm:
	@norminette -R CheckForbiddenSourceHeader src/*.c src/*.h src/*/*.c src/*/*.h src/*/*/*.c src/*/*/*.h libft/*c libft/*.h

sanitize:	re $(OBJS)
			@$(CC) $(DEBUG_F) $(OBJS) $(LIBFT_A) $(READLINE_A) $(READLINE_FLAG) -o $(NAME)
			$(info [Making with fsanitize=address ...])

re: 		fclean $(NAME)

.PHONY : all clean fclean re
