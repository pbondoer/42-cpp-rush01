# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 17:09:30 by vsteffen          #+#    #+#              #
#    Updated: 2018/10/07 18:53:06 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_GKrellM

# directories
INC_DIR		:= ./includes
SRC_DIR		:= ./src
OBJ_DIR		:= ./obj

# src / obj files
SRC 		:=	main.cpp \
				bytes.cpp \
				NcursesDisplay.cpp \
				WxmacDisplay.cpp \
				IMonitorModule.cpp \
				IMonitorDisplay.cpp \
				HostnameModule.cpp \
				UsernameModule.cpp \
				OsNameModule.cpp \
				DateTimeModule.cpp \
				CpuModule.cpp \
				RamModule.cpp \
				NetworkModule.cpp \
				GKrellM_wxapp.cpp \
				Frame_wxapp.cpp \
				Panels_wxapp.cpp

OBJ			:= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

# compiler
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror
CXXFLAGS	+= -O3 -march=native -pipe -flto

WXCFLAG		= `wx-config --cxxflags`
WXLIBFLAG	= `wx-config --libs`

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(WXCFLAG) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(WXCFLAG) $(WXLIBFLAG) -lcurses

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
