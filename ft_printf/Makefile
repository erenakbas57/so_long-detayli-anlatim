SOURCES 	= 	ft_printf.c ft_func.c

OBJECTS 	= 	$(SOURCES:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		= 	-Wall -Wextra -Werror

NAME		=	libftprintf.a

all 		: 	$(OBJECTS)
			$(AR) rc $(NAME) $(OBJECTS)

clean 		:
			$(RM) $(OBJECTS)

fclean 		: 	clean
			$(RM) $(NAME)

re 		: 	fclean all

.PHONY:	all clean fclean re