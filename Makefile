NAME		= libftprintf.a

CC			= gcc

src_libft	= ./libft

SRCS		= ft_printf.c \
			ft_output.c \
			ft_flag_formats.c \
			ft_tools.c \
			ft_handle_strings.c \
			ft_handle_char.c \
			ft_handle_numbers.c \
			ft_wprecision.c \

OBJS	= $(SRCS:.c=.o)

HEADS	= ft_printf.h

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -C ${src_libft}
			@ar rc $(NAME) $(OBJS) ${src_libft}/*.o
			@ranlib $(NAME)
			@echo "Done!"

all:		$(NAME)

debug:
			@${CC} ${FLAGS} main.c ft_*.c libft/*.c -g

clean:
			@$(RM) $(OBJS)
			@make clean -C ${src_libft}

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C ${src_libft}
			@echo "All Cleaned!"

re:			fclean all

.PHONY:		clean fclean all re
