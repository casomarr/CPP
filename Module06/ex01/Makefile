# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: octonaute <octonaute@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:13:39 by casomarr          #+#    #+#              #
#    Updated: 2024/03/24 18:40:55 by octonaute        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

NAME = serialize

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
# CFLAGS+= -g3

RM = rm -f

# **************************************************************************** #
#                                  DEPENDANCIES                                #
# **************************************************************************** #

###INCLUDES FOLDER
INCLUDES_FOLDER = includes/

###SRCS FOLDER
SRCS_FOLDER = srcs/

### INCLUDES
HEADERS = $(INCLUDES_FOLDER)/Serializer.hpp

### SOURCES
SRCS = main.cpp \
		$(SRCS_FOLDER)/Serializer.cpp \
		
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