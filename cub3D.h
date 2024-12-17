/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:01:54 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/17 17:48:16 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include "mlx.h"
# include "libft.h"

# define DISPLAY_WIDTH 2000
# define DISPLAY_HEIGHT 1400
# define TEXTURE_SIZE 64
# define ROTATION_SPEED 0.11
# define PLAYER_SPEED 0.22

# define DESTROY 17
# define ESC 65307
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define NORTH_TXT 0
# define SOUTH_TXT 1
# define EAST_TXT 2
# define WEST_TXT 3

# define HORIZONTAL_FLAG 0
# define VERTICAL_FLAG 1

typedef struct s_ray
{
	float	camera_orientation;
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	wall_dist;
	float	wall_x_offset;
	int		vertical_or_horiz_flag;
	int		wall_height_on_screen;
	int		wall_top;
	int		wall_bottom;
}	t_ray;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	int		left_or_right_flag;
	int		forward_or_backward_flag;
	int		rotation_flag;
	char	first_direction;
}	t_player;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		sl;
	int		nd;
}	t_img;

typedef struct s_textures_state
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	f_hx;
	unsigned long	c_hx;
	int				curr_txt_index;
	float			step;
	int				col;
	float			rank_address;
	int				rank;
}	t_txt_state;

typedef struct s_map_state
{
	char		*path;
	char		**file;
	int			fd;
	int			nb_lines;
	int			height;
	int			width;
	int			eom;
}	t_map_state;

typedef struct s_state
{
	void				*mlx;
	void				*window;
	int					window_width;
	int					window_height;
	t_img				image;
	t_player			player;
	t_ray				ray;
	char				**map;
	t_map_state			map_state;
	int					**textures;
	t_txt_state			txt_state;
}						t_state;

typedef struct s_rotation_helper
{
	float		rotation_value;
	float		cos_r;
	float		sin_r;
	float		save_dir_x;
	float		save_plane_x;
}				t_rotation_helper;

/* 
EXEC
*/
void	exec(t_state *s);
int		handle_key_press(int key, t_state *s);
int		handle_key_release(int key, t_state *s);
void	handle_moves(t_state *s);
void	make_move(t_state *s, float new_col_pos, float new_rank_pos);
void	raycasting(t_player *player, t_state *s);
void	rotate_player(t_state *s, int direction);
void	set_first_player_direction(t_state *s);
void	fill_frame(t_state *s, t_txt_state *txt_state, t_ray *ray, int col);

/* 
INIT
*/
void	init_raw_img(t_img *image);
void	init_img(t_state *s, t_img *m, int width, int height);
void	init_mlx(t_state *s);
void	init_ray(t_ray *ray);
void	init_state(t_state *s);
void	init_texture_img(t_state *s, t_img *m, char *path);
void	init_txt_state(t_txt_state *txt_state);
void	init_textures(t_state *s);

/* 
PARSING
*/
int		are_textures_ok(t_txt_state *textures);
int		fetch_raw_file(char *path, t_state *s);
int		fetch_scene_descr_content(t_state *s, char **file);
int		is_file_ok(char *path, int is_cub);
int		is_map_ok(t_state *s, char **map);
int		is_map_surrounded_by_walls(t_map_state *map_state, char **map);
int		make_map(t_state *s, char **file, int start);
void	parsing(t_state *s, char **av);
int		set_colors(t_txt_state *textures, char *line, int c);

/*
PARSING: parsing_helpers.c
*/
int		ft_isprint_nospace(int c);
size_t	max_row_len(t_map_state *map_state, int start);

/*
termination.c
*/
int		error_msg(char *error_msg);
void	exit_game(t_state *s, int ext);
int		exit_game_success(t_state *s);

#endif
