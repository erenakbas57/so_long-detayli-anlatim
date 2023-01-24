SOURCES 	= 	get_next_line.c get_next_line_utils.c

OBJECTS 	= 	$(SOURCES:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		= 	-Wall -Wextra -Werror

NAME		=	gnl.a

all 		: 	$(OBJECTS)
			$(AR) rc $(NAME) $(OBJECTS)

clean 		:
			$(RM) $(OBJECTS)

fclean 		: 	clean
			$(RM) $(NAME)

re 		: 	fclean all

.PHONY:	all clean fclean re