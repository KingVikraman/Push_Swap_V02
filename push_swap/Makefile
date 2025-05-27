#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:23:41 by rvikrama          #+#    #+#              #
#    Updated: 2025/05/27 21:53:27 by rvikrama         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME				= push_swap
CC					= cc
COMP				= -Wall -Werror -Wextra
CFLAGS				= $(COMP) -I $(INC_DIR) 
RM					= rm -rf
DEBUG				= -g3
THREAD_DEBUG		= -fsanitize=thread
MEMORY_DEBUG		= -fsanitize=memory
THREAD_FLAGS		= -pthread


INC_DIR			= Includes/
# OBJS_DIR		= bin/
# SRCS_DIR		= Source/

SRCS		:=	$(wildcard Source/Operations/*.c) \
			$(wildcard Source/Sort/*.c)	\
			$(wildcard Source/Utils/*.c) \
			Source/main.c

OBJS	:=	$(SRCS:%.c=bin/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm

bin/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) bin

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re



# .PHONY: all clean fclean re
# NAME			= push_swap
# CC				= cc
# COMP			= -Wall -Werror -Wextra
# CFLAGS			= $(COMP) -I$(INC_DIR)
# RM				= rm -rf

# INC_DIR			= Includes/

# SRCS := $(wildcard Source/Operations/*.c) \
# 		$(wildcard Source/Sort/*.c) \
# 		$(wildcard Source/Utils/*.c) \
# 		Source/main.c

# OBJS := $(SRCS:%.c=bin/%.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# bin/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	$(RM) bin

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
