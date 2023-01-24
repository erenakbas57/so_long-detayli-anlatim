SOURCES	=	ft_strlen.c ft_strchr.c ft_strjoin.c ft_itoa.c



NAME 			= libft.a

OBJECTS 		= $(SOURCES:.c=.o)

CC 				= gcc

RM 				= rm -f

CFLAGS 			= -Wall -Werror -Wextra

all: 			$(NAME)


$(NAME): 		$(OBJECTS)
			$(AR) rc $(NAME) $(OBJECTS)

clean:
				$(RM) $(OBJECTS)

fclean: 		clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re bonus