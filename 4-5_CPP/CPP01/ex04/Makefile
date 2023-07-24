# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 11:21:33 by arabenst          #+#    #+#              #
#    Updated: 2023/07/22 13:52:58 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	replace

INCDIR		:=	./include
SRCDIR		:=	./src
OBJDIR		:=	./obj

INCS		:=	$(wildcard $(INCDIR)/*.hpp)
SRCS		:=	$(wildcard $(SRCDIR)/*.cpp)
OBJS		:=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

CC			:=	c++
CPPFLAGS	:=	-Wall -Werror -Wextra -std=c++98

RM			:=	rm
RMFLAGS		:=	-rf

$(NAME): $(OBJS) | $(INCS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CPPFLAGS)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re