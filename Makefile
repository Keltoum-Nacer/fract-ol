SRCS = fractal.c fractal_utils.c pixels.c events.c mandelbrot_julia.c burning_ship.c mlx_func.c
OFILES = $(SRCS:.c=.o)
CC = CC
NAME = fractol
CFLAGS = -Wall -Wextra -Werror 
all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME) -L. -lmlx -framework Appkit -framework OpenGl

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
