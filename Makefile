##
## Makefile for Makefile in /home/paglia_f//WorkOffline/printf
##
## Made by floran pagliai
## Login   <paglia_f@epitech.net>
##
## Started on  Mon Nov 14 10:39:32 2011 floran pagliai
## Last update Thu Jan 31 17:11:04 2013 floran pagliai
##

NAME= 	moulinette/trade

SRC= 	src/main.cpp\
	src/Logger.cpp\
	src/Trader.cpp

OBJ=	$(SRC:.cpp=.o)

FLAG=	-g -Wall

all:	$(OBJ)
	g++ $(FLAG) -o $(NAME) $(OBJ)
	make clean
	./moulinette/trade_moulinette.php -f moulinette/BAC1.txt -p $(NAME) -m 1000 -o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)