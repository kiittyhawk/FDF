/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:50 by jgyles            #+#    #+#             */
/*   Updated: 2021/11/16 13:46:51 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	char	**nums;
	int		i;

	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	nums = ft_split(line, ' ');
	i = 0;
	width = 0;
	while (nums[i])
	{
		width++;
		free(nums[i]);
		i++;
	}
	free(nums);
	free(line);
	close(fd);
	return (width);
}

static void	set_matrix(int *z_matrix, char *line)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		z_matrix[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *filename, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	data->height = get_height(filename);
	data->width = get_width(filename);
	data->z_matrix = (int **)malloc(sizeof(int **) * (data->height + 1));
	while (i < data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int *) * (data->width + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		set_matrix(data->z_matrix[i++], line);
		free(line);
	}
	close(fd);
}
