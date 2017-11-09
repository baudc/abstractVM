##
## Makefile for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
## 
## Made by nogue_k
## Login   <nogue_k@epitech.net>
## 
## Started on  Mon Jul 24 11:19:55 2017 Kévin Nogué
## Last update Wed Jul 26 15:19:40 2017 baud
##

SRCS	=	main.cpp \
		Memory.cpp \
		Parser.cpp \
		Factory.cpp \
	  	Int8.cpp \
	  	Int16.cpp \
	  	Int32.cpp \
	  	Float.cpp \
	  	Double.cpp \
	  	BigDecimal.cpp \
		tools.cpp \
		Exception.cpp

CC	=	g++

RM	=	rm -rf

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	abstractVM

CXXFLAGS	=	-std=c++11 -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
