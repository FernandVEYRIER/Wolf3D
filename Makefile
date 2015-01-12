##
## Makefile for  in /home/veyrie_f/rendu/MUL_2014_wolf3d
## 
## Made by fernand veyrier
## Login   <veyrie_f@epitech.net>
## 
## Started on  Sun Dec  7 19:39:09 2014 fernand veyrier
## Last update Sat Dec 20 17:11:56 2014 fernand veyrier
##

CC		= gcc

RM		= rm -f

NAME		= wolf3d

SRCS		= wolf.c \
		  drawing.c \
		  map_handler.c \
		  event_handler.c \
		  event_handler_next.c \
		  drawing_next.c \
		  wolf_next.c \
		  weapon_handler.c \
		  utils.c \
		  ./system_lib/strlcpy.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -I./include -O2

LIB		= -L /usr/lib64 -lmlx -L /usr/lib64/X11 -lXext -lX11 -lm

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
