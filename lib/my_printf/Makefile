##
## Makefile for 512 in /home/chauch_p/temp/2048/lib/my_printf
## 
## Made by Pierre Chauchoy
## Login   <chauch_p@epitech.net>
## 
## Started on  Fri May 13 02:18:02 2016 Pierre Chauchoy
## Last update Fri May 13 02:18:02 2016 Pierre Chauchoy
##

RM		= rm -f

CP		= cp

LIB_PRINTF	= .

INC_DIR		= ../../include/

LIB_DIR		= ../

SRCS		= $(LIB_PRINTF)/my_printf.c \
		  $(LIB_PRINTF)/my_printf_func_1.c \
		  $(LIB_PRINTF)/my_printf_func_2.c \
		  $(LIB_PRINTF)/my_printf_func_3.c \
		  $(LIB_PRINTF)/my_printf_func_4.c \
		  $(LIB_PRINTF)/my_printf_func_5.c

INC		= $(LIB_PRINTF)/my_printf.h

OBJS		= $(SRCS:.c=.o)

NAME		= libprintf

LIB		= $(NAME).a

all:		$(NAME)

$(NAME):		$(OBJS)
		ar rc $(LIB) $(OBJS)
		ranlib $(LIB)
		$(CP) $(LIB) $(LIB_DIR)
		$(CP) $(INC) $(INC_DIR)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(LIB)

re: 		fclean all

.PHONY: 	all clean fclean re
