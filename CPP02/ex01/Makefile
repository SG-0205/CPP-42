# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 17:57:15 by sgoldenb          #+#    #+#              #
#    Updated: 2024/11/01 18:08:56 by sgoldenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cpp02_ex01

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

SRC_DIR = ./
OBJ_DIR = ./obj

SRC = $(wildcard $(SRC_DIR)/*.cpp)

OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
