NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			 map_fun/check_map.c map_fun/checks_fun.c map_fun/checks_fun2.c map_fun/free_map.c \
			 map_fun/get_map.c map_fun/get_num_of_coll.c map_fun/get_player_pos.c \
			 map_fun/map_error.c utils/ft_strchr.c utils/ft_strcmp.c \
			 utils/ft_strlen.c utils/error_msg.c graphical_fun/is_graphic_mlx.c keys/keys_handling.c \
			 map_fun/flood_fill.c map_fun/free_map_cpy.c map_fun/validate_map_file.c keys/display_move_count.c

SRCS_B = Bonus/so_long_bonus.c Bonus/get_next_line_bonus/get_next_line_bonus.c Bonus/get_next_line_bonus/get_next_line_utils_bonus.c \
			 Bonus/map_fun_bonus/check_map_bonus.c Bonus/map_fun_bonus/checks_fun_bonus.c Bonus/map_fun_bonus/checks_fun2_bonus.c Bonus/map_fun_bonus/free_map_bonus.c \
			 Bonus/map_fun_bonus/get_map_bonus.c Bonus/map_fun_bonus/get_num_of_coll_bonus.c Bonus/map_fun_bonus/get_player_pos_bonus.c \
			 Bonus/map_fun_bonus/map_error_bonus.c Bonus/utils_bonus/ft_strchr_bonus.c Bonus/utils_bonus/ft_strcmp_bonus.c \
			 Bonus/utils_bonus/ft_strlen_bonus.c Bonus/utils_bonus/error_msg_bonus.c Bonus/graphical_fun_bonus/is_graphic_mlx_bonus.c \
			 Bonus/keys_bonus/keys_handling_bonus.c Bonus/map_fun_bonus/flood_fill_bonus.c Bonus/map_fun_bonus/validate_map_file_bonus.c \
			 Bonus/graphical_fun_bonus/player_animation_bonus.c Bonus/graphical_fun_bonus/render_map_bonus.c Bonus/keys_bonus/display_move_count_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_B:.c=.o)
HEADER = include/so_long.h
HEADER_BONUS = Bonus/include_bonus/so_long_bonus.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -lmlx -framework OpenGL -framework Appkit -o $(NAME_BONUS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): %.o: %.c $(HEADER_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all bonus clean fclean re