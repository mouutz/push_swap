# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msahli <msahli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 19:42:30 by msahli            #+#    #+#              #
#    Updated: 2021/07/07 19:55:48 by msahli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS_SORTER =	./srcs/sorter/main.c \
				./srcs/sorter/short_suites/short_suites.c \
				./srcs/sorter/long_suites/step1_target_index.c \
				./srcs/sorter/long_suites/step2_keep_push.c \
				./srcs/sorter/long_suites/step3_find_shortest_action.c \
				./srcs/sorter/long_suites/step4_sort.c \

SRCS_COMMON =	./srcs/common/stack/stack_utils0.c \
				./srcs/common/stack/stack_utils1.c \
				./srcs/common/stack/stack_utils2.c \
				./srcs/common/stack/stack_utils3.c \
				./srcs/common/utils/utils0.c \
				./srcs/common/actions/push_stack.c \
				./srcs/common/actions/reverse_rotate_stack.c \
				./srcs/common/actions/rotate_stack.c \
				./srcs/common/actions/swap_stack.c \
				./srcs/common/parsing/parsing_utils.c \
				./srcs/common/exit/exit.c \

SRCS_CHECKER =	./srcs/checker_bonus/get_next_line.c \
				./srcs/checker_bonus/get_next_line_utils.c \
				./srcs/checker_bonus/main.c \

OBJS_SORTER =	${SRCS_SORTER:.c=.o}
OBJS_COMMON =	${SRCS_COMMON:.c=.o}
OBJS_CHECKER =	${SRCS_CHECKER:.c=.o}

INCLUDE = 		./srcs/include

NAME =			push_swap
NAME_CHECKER =	checker

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM = 		rm -rf

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS_COMMON} ${OBJS_SORTER}
			${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME} ${OBJS_COMMON} ${OBJS_SORTER}

${NAME_CHECKER}:	${OBJS_COMMON} ${OBJS_CHECKER}
					${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME_CHECKER} ${OBJS_COMMON} ${OBJS_CHECKER}

clean:
			${RM} ${OBJS_COMMON} ${OBJS_CHECKER} ${OBJS_SORTER}

fclean:		clean
			${RM} ${NAME} ${NAME_CHECKER}

re:			fclean all

bonus:		checker

.PHONY:		checker bonus all clean fclean re
