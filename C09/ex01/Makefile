CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = srcs/ft_putchar.c \
       srcs/ft_swap.c \
       srcs/ft_putstr.c \
       srcs/ft_strlen.c \
       srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INC = -I ./includes/ft.h

.c.o :
	$(CC) $(CFLAGS) $(INC) -c $(<) -o $(<:.c=.o)

all:		$(TARGET)

$(TARGET):	$(OBJS)
	ar rcs	$(@) $(^)
clean:
	rm -rf	$(OBJS)
fclean:	clean
	rm -rf $(TARGET)
re:	clean all
