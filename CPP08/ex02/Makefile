# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 17:57:15 by sgoldenb          #+#    #+#              #
#    Updated: 2025/04/11 13:06:35 by sgoldenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

NAME = MutantStack 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEP)
