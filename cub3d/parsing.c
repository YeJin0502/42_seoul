/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 21:23:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 21:23:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img *make_img(char *filename, t_info *info)
{
    t_img *img;

    img = (t_img *)malloc(sizeof(t_img));
    img->image = mlx_xpm_file_to_image(info->mlx, filename, &(img->width), &(img->height));
    img->image_data = mlx_get_data_addr(img->image, &(img->bpp), &(img->size_line), &(img->endian));
    return (img);
}

void parsing_wall(char *line, char *wall, t_ps *ps)
{
    char *filename;

    filename = line + 2;
    while (*filename == ' ') // skip_space로 만들면 더 읽기 쉬우려나?
        filename++;
    if (ft_strncmp(wall, "NO", 2) == 0)
        ps->no = ft_strdup(filename); // strdup으로 해줘야 다른곳에서 안날아가고 유지되나?
    else if (ft_strncmp(wall, "SO", 2) == 0)
        ps->so = ft_strdup(filename);
    else if (ft_strncmp(wall, "WE", 2) == 0)
        ps->we = ft_strdup(filename);
    else if (ft_strncmp(wall, "EA", 2) == 0)
        ps->ea = ft_strdup(filename);
    else
        ps->s = ft_strdup(filename);
}

void init_info_wall(t_info *info, t_ps *ps)
{
    info->no = make_img(ps->no, info);
    info->so = make_img(ps->so, info);
    info->we = make_img(ps->we, info);
    info->ea = make_img(ps->ea, info);    
}

char	*c3_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
    size_t  s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
    {
        s1_len = 0;
		s2_len = ft_strlen(s2);
    }
	else if (s1 && !s2)
    {
		s1_len = ft_strlen(s1);
        s2_len = 0;
    }
	else
    {
		s1_len = ft_strlen(s1);
        s2_len = ft_strlen(s2);
    }
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (!ret)
		return (0);
	ret[s1_len + s2_len] = '\0';
	i = 0;
	j = 0;
	while(i < s1_len)
		ret[i++] = s1[j++];
	j = 0;
	while (i < s1_len + s2_len)
		ret[i++] = s2[j++];
	return (ret);
}

void init_info_map(char *line, t_ps *ps, t_info *info)
{
    char *joined_array;

    if (info->map_width < ft_strlen(line))
        info->map_width = ft_strlen(line);
    info->map_height++;
    joined_array = c3_strjoin(info->map, line); // int 형이라 join을 못쓴다.
    free(info->map);
    info->map = joined_array;
}

void init_info_fc(char *line, char *fc, t_info *info, t_ps *ps)
{
    char *rgb;

    rgb = line + 1;
    while (*rgb == ' ') // skip_space로 만들면 더 읽기 쉬우려나?
        rgb++;
    if (ft_strncmp(fc, "F", 1) == 0)
    {
        info->f[0] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->f[1] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->f[2] = ft_atoi(rgb);
        ps->f_complete = 1;
    }
    else
    {
        info->c[0] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->c[1] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->c[2] = ft_atoi(rgb); 
        ps->c_complete = 1;
    }
}

void init_info_win(char *line, t_ps *ps, t_info *info)
{
    char *adr;

    adr = line + 1;
    while (*adr == ' ')
        adr++;
    info->win_width = ft_atoi(adr);
    adr = ft_strchr(adr, ' ');
    info->win_height = ft_atoi(adr);
}

void convert_map(t_info *info)
{
    while (*(info->map))
    {
        if (*(info->map) == ' ')
            *(info->map) = 0;
        else if (*(info->map) == '0')
            *(info->map) = 0;
        else if (*(info->map) == '1')
            *(info->map) = 1;
        // else if ()
        (info->map)++;
    }
}

void init_info_test(char *filename, t_info *info)
{
    t_ps *ps;
    int fd;
    char *line;

    ps = (t_ps *)malloc(sizeof(t_ps));
    // ft_memset(ps, 0, sizeof(t_ps)); // 동적할당에는 sizeof 쓰면 안된다고 들었는데.. 되나? ps가 아니라 t_ps라고 하면 되나?
    fd = open(filename, O_RDONLY);
    line = 0;
    while ((get_next_line(fd, &line) || ft_strlen(line)))
    {
        if (ft_strnstr(line, "R ", 2))
            init_info_win(line, ps, info);
        else if (ft_strnstr(line, "NO ", 3))
            parsing_wall(line, "NO", ps);
        else if (ft_strnstr(line, "SO ", 3))
            parsing_wall(line, "SO", ps);
        else if (ft_strnstr(line, "WE ", 3))
            parsing_wall(line, "WE", ps);
        else if (ft_strnstr(line, "EA ", 3))
            parsing_wall(line, "EA", ps);
        else if (ft_strnstr(line, "F ", 2))
            init_info_fc(line, "F", info, ps);
        else if (ft_strnstr(line, "C ", 2))
            init_info_fc(line, "C", info, ps);
        else if (ft_strnstr(line, "S ", 2))
            parsing_wall(line, "S ", ps);
        else if (ft_strlen(line)) // 맵을 한줄로 저장. 근데 ft_strlen이 있는 줄만 해야겠지..?
            init_info_map(line, ps, info); // 몇줄 될지 모르니까 연결리스트 쓰면 좋을것같은데...
        // parsing_map(info, ps);
        free(line);
    }
    // printf("[%s]\n", ps->no);
    // printf("[%s]\n", ps->so);
    // printf("[%s]\n", ps->we);
    // printf("[%s]\n", ps->ea);
    // printf("(%d, %d, %d)\n", info->f[0], info->f[1], info->f[2]);
    // printf("(%d, %d, %d)\n", info->c[0], info->c[1], info->c[2]);
    // printf("%d, %d, %d\n", info->map[0], info->map[1], info->map[2]);
    // printf("(%d, %d)\n", info->map_width, info->map_height);
    // printf("(%d, %d)\n", info->win_width, info->win_height);

    info->mlx = mlx_init();
    info->win = mlx_new_window(info->mlx, info->win_width, info->win_height, "gmoon");
    init_info_wall(info, ps);
    convert_map(info);

    info->tile_width = info->win_width / info->map_width;
    info->tile_height = info->win_height / info->map_height;



    free(ps->no);
    free(ps->so);
    free(ps->we);
    free(ps->ea);
    free(ps->s);
    free(ps);
}
