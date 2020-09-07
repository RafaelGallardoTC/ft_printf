SRCS	= ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_calloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strnstr.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strncpy.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putstr_len.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_nbrlen.c \

BNSRCS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \


OBJS	= $(SRCS:.c=.o)

BNOBJS = $(BNSRCS:.c=.o)

NAME	= libft.a

HEADS	= libft.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

bonus:		$(BNOBJS) $(OBJS)
			@ar rc $(NAME) $(BNOBJS)
			@ranlib $(NAME)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(BNOBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		clean fclean all re
