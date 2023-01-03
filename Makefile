NAME		= libftprintf.a

INCLUDE 	= ./include
SRC		= ./src

CFLAGS		= -Wall -Wextra -Werror -I./include
CC		= cc
FLAGLIB		= -rcs
RM		= rm -f

LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a

FT_PRINTF	= ft_printf.c ft_printf_utils.c ft_pointer.c print_hex.c 
OBJECTS		= $(FT_PRINTF:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@echo "$(NAME)"
	@cp $(LIBFT) $(NAME)
	@ar $(FLAGLIB) $(NAME) $(OBJECTS)
	@ranlib $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)

%.o: $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$<"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJECTS)

fclean:		clean
			@$(MAKE) fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re: fclean all


