NAME			= lem_in
CC				= gcc
LIBFT_DIRECTORY = ./libft
SRC_DIR 		= ./srcs/
ROOMS_DIR		= $(SRC_DIR)rooms/
DEBUG_DIR		= $(SRC_DIR)debug/
LIBRARIES 		= -lft -Llibft
LIBFT			= ./libft/*
INCLUDES 		= -I./libft/includes -I./includes

# ----- Colors -----
BLACK			:="\033[1;30m"
RED				:="\033[1;31m"
GREEN			:="\033[1;32m"
CYAN			:="\033[1;35m"
PURPLE			:="\033[1;36m"
WHITE			:="\033[1;37m"
EOC				:="\033[0;0m"
# ==================

SRCS		= $(SRC_DIR)main.c $(SRC_DIR)val_funcs.c $(SRC_DIR)validate.c $(DEBUG_DIR)display.c
SRCS		+= $(ROOMS_DIR)room_handler.c  $(ROOMS_DIR)room_nav.c
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(SRCS) $(LIBFT)
		@cd ./libft && make
		@echo $(GREEN)Built libft.$(EOC);
		@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LIBRARIES) -o $(NAME)
		@echo $(GREEN)"Compiled lem_in." $(EOC)

clean:
		@/bin/rm -f $(OBJS)
		@cd ./libft && make clean

fclean: clean
		@/bin/rm -f $(NAME)
		@cd ./libft && make fclean

re: fclean all
