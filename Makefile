NAME_ONE	=	philo_one
NAME_TWO	=	philo_two
NAME_THREE	=	philo_three
SRCS_PATH	=	./
OBJS_PATH	=	./objs
INC_PATH	=	./
HEAD		=	philosophers.h

SRCS		=	philosophers.c \
				philo_factory.c \
				philo_methods.c \
				simulation.c \
				options.c \
				utils.c \
				error.c \
				ft_dlst.c

OBJS		=	$(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))
RM			=	rm -f
RM_DIR		=	rm -rf
CFLAGS		=	-Wall -Werror -Wextra
CC			=	gcc
INC			=	-I $(INC_PATH)

.PHONY: all init clean fclean re norm

all: init $(NAME_ONE) $(NAME_TWO) $(NAME_THREE)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c $(HEAD)
	@ echo "compile $@"
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@ -g

$(NAME_ONE):	$(HEAD)	$(OBJS)
	@ $(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME_ONE)

$(NAME_TWO):
	@ echo "not now"

$(NAME_THREE):
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
