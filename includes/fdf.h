/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:46:14 by jgyles            #+#    #+#             */
/*   Updated: 2021/11/16 15:56:51 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_fdf {
	int		height;
	int 	width;
	int		**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	nook;
	int		flag;
}				t_fdf;

# include <mlx.h>
# include "libft.h"
# include <math.h>
# include <stdint.h>
# include "get_next_line.h"

void	read_file(char *filename, t_fdf *data);
void	draw(t_fdf *data);
int		get_max(float a, float b);
float	mod(float i);
int		get_color(int z, int z1);