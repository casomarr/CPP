# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:13:39 by casomarr          #+#    #+#              #
#    Updated: 2024/02/28 14:56:13 by casomarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

NAME = animal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
# CFLAGS+= -g3

RM = rm -f

# **************************************************************************** #
#                                  DEPENDANCIES                                #
# **************************************************************************** #

### INCLUDES
HEADERS = Animal.hpp \
		Cat.hpp \
		Dog.hpp \
		WrongAnimal.hpp \
		WrongCat.hpp \

### SOURCES
SRCS = main.cpp \
	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \

### OBJECTS
OBJS = $(SRCS:.cpp=.o)

# Dependency rules
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#                                  MAIN TARGET                                 #
# **************************************************************************** #

### BUILD
all: $(NAME)

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

### CLEANING
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

### REBUILD
re: fclean all

# **************************************************************************** #
#                                   PHONIES                                    #
# **************************************************************************** #

.PHONY: all clean fclean re