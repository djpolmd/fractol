NAME = fractol

N_INC = fractol.h

N_SRCS =	fractol.c\
			helper.c\
			hooker.c\
			multithread.c\
			onscreen.c\
			f_mandelbrot.c\
			f_julia.c\
			f_burningship.c\
			f_tricorn.c

X_LFT = -L$(P_LFT) -lft
X_MLX = -L$(P_MLX) -lmlx -framework OpenGL -framework AppKit

P_SRCS = source/
P_OBJ = objects/
I_INC = includes
I_LFT = libft/includes
P_LFT = libft
P_MLX = minilibx

NOC=\033[0m
OKC=\033[33m
ERC=\033[34m
WAC=\033[35m

CC = gcc
CC_FLAGS = -g -Wall -Wextra -Werror

INC = $(addprefix -I,$(I_INC) $(I_LFT) $(P_MLX))
SRC = $(addprefix $(P_SRCS),$(N_SRCS))
OBJ = $(addprefix $(P_OBJ),$(OBJ_NAME))

OBJ_NAME = $(N_SRCS:.c=.o)

all: $(NAME)

project: clean proj

proj: $(OBJ)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(X_LFT) $(X_MLX)
	@echo "$(OKC)$(NAME): compilation success!$(NOC)"
	@echo "Commands: 'julia' pentru JULIA, 'bship' pentru burningship, 'mandelbrot' pentru Mandelbrot, 'tricorn' pentru tricorn"

$(NAME): $(OBJ)
	@make -C $(P_LFT)
	@make -C $(P_MLX)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(X_LFT) $(X_MLX)
	@echo "$(OKC)$(NAME): ready$(NOC)"
	@echo "Commands: 'julia' pentru JULIA, 'bship' pentru Burningship, 'mandelbrot' pentru Mandelbrot, 'tricorn' pentru Tricorn"

$(P_OBJ)%.o: $(P_SRCS)%.c
	@echo "$(OKC)\c"
	@mkdir -p $(P_OBJ)
	@$(CC) $(CC_FLAGS) -o $@ -c $^ $(INC)
	@echo "$(NOC)\c"

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(P_OBJ)
	@echo "$(WAC)$(NAME): removing ./obj/$(NOC)"

fclean: clean
	@make -C $(P_LFT) fclean
	@make -C $(P_MLX) clean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): removing executable$(NOC)"

re: fclean all
