# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:13:39 by casomarr          #+#    #+#              #
#    Updated: 2024/03/05 14:07:12 by casomarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

NAME = materia

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
# CFLAGS+= -g3

RM = rm -f

# **************************************************************************** #
#                                  DEPENDANCIES                                #
# **************************************************************************** #

### INCLUDES
HEADERS = AMateria.hpp \
		Ice.hpp \
		Cure.hpp \
		Character.hpp \
		MateriaSource.hpp \
		ICharacter.hpp \
		IMateriaSource.hpp \

### SOURCES
SRCS = main.cpp \
		AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp \
		MateriaSource.cpp \

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

run: re
	-./$(NAME)

# **************************************************************************** #
#                                   PHONIES                                    #
# **************************************************************************** #

.PHONY: all clean fclean re run