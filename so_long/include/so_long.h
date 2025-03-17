/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamiri <aylamiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:34:06 by aylamiri          #+#    #+#             */
/*   Updated: 2025/03/16 09:54:47 by aylamiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <mlx.h>

# define CLOSE 17
# define BUFFER_SIZE 4
# define ESC_KEY 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char			**map;
	int				col;
	int				row;
	int				collectibles;
	t_vector		player;
}	t_map;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	void		*img;
	int			iw;
	int			ih;
	size_t		ww;
	size_t		wh;
	t_map		map;
	void		*textures[5];
	int			fd;
	int			can_exit;
	size_t		mv_counter;
}	t_program;

size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		extention_error(void);
void		syntaxe_error(void);
int			map_len(int fd);
void		get_map(char *file_name, t_program *game);
void		check_map(char *file_name, t_program *game);
void		check_dir(char *file_name);
int			check_extention(const char *src, const char *to_find);
int			check_occur(t_program game);
void		err_map(t_program *game);
int			in_set(char c);
int			check_rectangular(t_program game);
int			check_characters(t_program game);
int			check_player(t_program game);
int			check_walls(t_program game);
void		free_map(t_program *game);
void		free_map_cpy(char **map);
int			ft_strchr(const char *s, int c);
void		get_num_of_coll(t_program *game);
void		get_player_pos(t_program *game);
int			check_exit(t_program game);
int			close_handler(t_program *game);
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_free(t_program *game);
void		err_rectangular(t_program *game);
void		err_characters(t_program *game);
void		err_walls(t_program *game);
void		err_ecp(t_program *game);
int			is_graphic_mlx(t_program *game);
void		get_map_dimensions(t_program *game);
void		load_texture(t_program *game, int index, char *f);
void		load_img(t_program *game);
void		render_map(t_program *game);
void		move_player(t_program *game, int new_x, int new_y);
void		player_action(int key, t_program *game);
int			handle_keys(int key, t_program *game);
char		**ft_split(char *s, char c);
int			check_ff(t_program *game);
void		fd_error(void);
void		empty_map(int fd);
void		display_move_count(t_program *game);
void		validate_map_file(char *file_name);
char		*ft_itoa(int n);
#endif