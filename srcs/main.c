/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:36 by jgyles            #+#    #+#             */
/*   Updated: 2021/11/16 16:04:36 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	conditions(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

int	key(int key, t_fdf *data)
{
	printf("%d\n", key);
	conditions(key, data);
	if (key == 24)
		data->zoom += 10;
	if (key == 27)
		data->zoom -= 10;
	if (key == 30)
		data->nook += 0.2;
	if (key == 33)
		data->nook -= 0.2;
	if (key == 48)
		data->flag++;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf	*data;
	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->zoom = 20;
	data->nook = 0.2;
	data->flag = 1;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

	draw(data);
	mlx_key_hook(data->win_ptr, key, data);
	mlx_loop(data->mlx_ptr);
}
