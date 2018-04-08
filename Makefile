# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 17:09:30 by vsteffen          #+#    #+#              #
#    Updated: 2018/04/07 22:25:18 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_GKrellM

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

ROOT  	=	.
OPATH 	=	$(ROOT)/
CPATH 	=	$(ROOT)/

WXCFLAG		= `wx-config --cxxflags`
WXLIBFLAG	= `wx-config --libs`

SRC =	main.cpp \
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
		Frame_wxapp.cpp

OBJ_NAME = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OPATH),$(OBJ_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building $@"
	@clang++ $(CFLAGS) $(OBJ) -o $@ $(WXCFLAG) $(WXLIBFLAG)

$(OPATH)/%.o: $(CPATH)/%.cpp
	@clang++ $(CFLAGS) -c $< -o $@ $(WXCFLAG)

clean:
	@echo "Clean rule"
	@rm -f $(OBJ)

fclean: clean
	@echo "Fclean rule"
	@rm -f $(NAME)

re: fclean all
