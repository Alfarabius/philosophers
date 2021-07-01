NAME		=	philo
NAME_BONUS	=	philo_bonus
SRCS_PATH	=	./
OBJS_PATH	=	./objs
INC_PATH	=	./
HEAD		=	philosophers.h

SRCS		=	philosophers.c \
				philo_factory.c \
				philo_methods.c \
				philo_start.c \
				simulation.c \
				options.c \
				utils.c \
				error.c \
				forks.c

OBJS		=	$(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))
RM			=	rm -f
RM_DIR		=	rm -rf
CFLAGS		=	-Wall -Werror -Wextra
CC			=	gcc
INC			=	-I $(INC_PATH)

.PHONY: all init clean fclean re norm

all: init $(NAME)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c $(HEAD)
	@ echo "compile $@"
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@ -g

$(NAME):	$(HEAD)	$(OBJS)
	@ $(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

$(NAME_BONUS):
	@ echo "not now"

init:
	@ mkdir -p $(OBJS_PATH)

clean:
	@ echo "clean"
	@ $(RM) $(OBJS)
	@ $(RM_DIR) $(OBJS_PATH)

fclean: clean
	@ $(RM) $(NAME)

norm:
	@ norminette $(addprefix $(SRCS_PATH)/, $(SRCS)) $(HEAD)

re: fclean all
