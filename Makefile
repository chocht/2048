##
## Makefile for 512 in /home/chauch_p/temp/2048
## 
## Made by Pierre Chauchoy
## Login   <chauch_p@epitech.net>
## 
## Started on  Fri May 13 02:12:45 2016 Pierre Chauchoy
## Last update Sat May 14 05:44:17 2016 Pierre Chauchoy
##

CC	= gcc

RM	= rm -f

NAME	= 512

DIR	= srcs

SRCS	= $(DIR)/main.c \
	  $(DIR)/usual_functions_1.c \
	  $(DIR)/usual_functions_2.c \
	  $(DIR)/i512.c \
	  $(DIR)/i512_2.c \
	  $(DIR)/play.c \
	  $(DIR)/play2.c \
	  $(DIR)/play3.c \
	  $(DIR)/up_key.c \
	  $(DIR)/right_key.c \
	  $(DIR)/down_key.c \
	  $(DIR)/left_key.c \
	  $(DIR)/init_data.c \
	  $(DIR)/list.c \
	  $(DIR)/list_swap.c \
	  $(DIR)/list_del.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -I/home/${USER}/.froot/include/
CFLAGS	+= -L/home/${USER}/.froot/lib/
CFLAGS	+= -llapin -lsfml-audio -lsfml-graphics -lsfml-window
CFLAGS	+= -lsfml-system -lstdc++ -ldl -lm
CFLAGS	+= -L./lib/ -lprintf
CFLAGS	+= -I./include/
CFLAGS	+= -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
