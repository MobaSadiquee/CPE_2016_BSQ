##
## Makefile for Makefile in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ
## 
## Made by Sadiqu-m
## Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
## 
## Started on  Mon Dec  5 13:07:48 2016 Sadiqu-m
## Last update Fri Dec 16 15:50:08 2016 Sadiqu-m
##

NAME            = bsq

SRC             = ./src/my_basic_fonc.c \
                  ./src/my_basic_nbr.c \
		  ./src/get_map.c \
		  ./src/get_info.c \
		  ./src/display_map.c \
		  ./src/bsq.c \
		  ./src/main.c

CC              = gcc

RM              = rm -rf

OBJ             = $(SRC:.c=.o)

CFLAGS          = -I./include -I.

all:
	@make --no-print-directory $(NAME)

$(NAME):        $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all
