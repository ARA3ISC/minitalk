NAME = client
S_NAME = server

B_NAME = client_bonus
B_S_NAME = server_bonus

CC = cc
CFLAGS = -Werror -Wextra -Wall
RM = rm -f

SRC = cl/client.c libft/ft_atoi.c printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putnbr_add.c \
printf/ft_putnbr_u_dec.c printf/ft_putstr.c printf/ft_strlen.c
S_SRC = serv/server.c printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putnbr_add.c \
printf/ft_putnbr_u_dec.c printf/ft_putstr.c printf/ft_strlen.c

B_SRC = bonus/client_bonus.c printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putnbr_add.c \
printf/ft_putnbr_u_dec.c printf/ft_putstr.c printf/ft_strlen.c libft/ft_atoi.c
B_S_SRC = bonus/server_bonus.c printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putnbr_add.c \
printf/ft_putnbr_u_dec.c printf/ft_putstr.c printf/ft_strlen.c libft/ft_atoi.c

OBJ = $(SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)
B_S_OBJ = $(B_S_SRC:.c=.o)

all: $(S_NAME) $(NAME)

bonus: $(B_NAME) $(B_S_NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[38;5;200mDone !"

$(S_NAME): $(S_OBJ)
	@$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJ)

$(B_NAME): $(B_OBJ)
	@$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJ)

$(B_S_NAME):$(B_S_OBJ)
	@$(CC) $(CFLAGS) -o $(B_S_NAME) $(B_S_OBJ)

%.o: %.c
	@printf "\033[0;33mGenerating objects... %-100.900s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(S_OBJ)
	@$(RM) $(OBJ)
	@$(RM) $(B_OBJ)
	@$(RM) $(B_S_OBJ)

fclean: clean
	@$(RM) $(S_NAME)
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@$(RM) $(B_S_NAME)

re: fclean all bonus


