##
## Makefile for Makefile in /home/paglia_f//WorkOffline/printf
##
## Made by floran pagliai
## Login   <paglia_f@epitech.net>
##
## Started on  Mon Nov 14 10:39:32 2011 floran pagliai
## Last update Thu Jan 31 16:31:35 2013 floran pagliai
##

NAME= 	trade

SRC= 	main.cpp\
	Trade.cpp

OBJ=	$(SRC:.cpp=.o)

FLAG=	-g -Wall

LIB=	include

all:	$(OBJ)
	g++ $(FLAG) -o $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)