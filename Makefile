
NAME = minishell
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

SRC = main.c run/run_redir_exec.c run/run_utils.c run/run_builtin.c \
		run/run_bonus_pipe.c parser/wildcards.c parser/wildcards_utils.c \
		parser/quotes.c parser/var.c parser/var_len.c parser/var_utils.c \
		parser/parse.c parser/parse_utils.c parser/parse_token.c \
		parser/parse_heredoc.c \
		constructors.c env/env_utils.c env/env_list.c env/env_ft.c \
		signals/sig_set.c signals/sig_utils.c errors.c free.c print_tree.c \
		utils.c \

SRC += builtins/cd_extra.c builtins/cd.c builtins/echo.c builtins/env.c \
		builtins/exit.c builtins/export.c builtins/pwd.c builtins/unset.c \

SRC += uwu/uwu_one.c uwu/uwu_two.c uwu/uwu_three.c uwu/rizzer.c

CC = cc
CFLAGS = -Wall -Werror -Wextra
RFLAGS = -I /opt/homebrew/opt/readline/include -lreadline -L /opt/homebrew/opt/readline/lib

COMP = $(CC) $(CFLAGS) $(RFLAGS) $(LIB)

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
						$(MAKE) -C ./libft 
						$(COMP) $(OBJ) -o $(NAME)

%.o : %.c
						$(CC) -I /opt/homebrew/opt/readline/include -c $< -o $@

bonus: all

clean:
		$(RM) $(OBJ)
		$(MAKE) fclean -C ./libft
		
fclean:	clean
		$(RM) $(NAME)

re:		fclean all

PHONY: 	all bonus fclean clean re