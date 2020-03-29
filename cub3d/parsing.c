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

t_img *make_img(char *filename, t_info *info)
{
    t_img *img;

    img = (t_img *)malloc(sizeof(t_img));
    img->image = mlx_xpm_file_to_image(info->mlx, filename, &(img->width), &(img->height));
    img->image_data = mlx_get_data_addr(img->image, &(img->bpp), &(img->size_line), &(img->endian));
    return (img);
}

void init_info_wall(t_info *info, t_ps *ps)
{
    info->no = make_img(ps->no, info);
    info->so = make_img(ps->so, info);
    info->we = make_img(ps->we, info);
    info->ea = make_img(ps->ea, info);
    // info->s = make_img(ps->s, info);
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

void init_info_map_wh(char *line, t_info *info)
{
    // char *joined_array;

    if (info->map_width < ft_strlen(line))
        info->map_width = ft_strlen(line);
    info->map_height++;
    // joined_array = ft_strjoin(info->map, line); // int 형이라 join을 못쓴다.
    // free(info->map);
    // info->map = joined_array;
}

// void init_info_map(char *line, t_info *info)
// {
//     char **map;
//     int i;

//     map = (char **)malloc(sizeof(char *) * info->map_height);
//     i = -1;
//     while (++i < info->map_height)
//     {
//         map[i] = (char *)malloc(info->map_width + 1);
//         ft_strlcpy(map[i], line, info->map_width + 1);
//         printf("[%s]\n", map[i]);
//     }
//     info->map = map;
// }

void convert_map(t_info *info)
{
    int i;
    int j;

    i = -1;
    while (++i < info->map_height)
    {
        j = -1;
        while (++j < info->map_width)
        {
            if (info->map[i][j] == ' ')
                info->map[i][j] = -1;
            else if (info->map[i][j] == '0')
                info->map[i][j] = 0;
            else if (info->map[i][j] == '1')
                info->map[i][j] = 1;
            else if (info->map[i][j] == '2')
                info->map[i][j] = 2;
            else if (info->map[i][j] == 'N')
            {
                info->map[i][j] = 0;
                info->x = info->tile_width * j + info->tile_width / 2;
                info->y = info->tile_height * i + info->tile_height / 2;
                info->view_angle = 1.5 * PI;
            }
            else if (info->map[i][j] == 'S')
            {
                info->map[i][j] = 0;
                info->x = info->tile_width * j + info->tile_width / 2;
                info->y = info->tile_height * i + info->tile_height / 2;
                info->view_angle = 0.5 * PI;
            }
            else if (info->map[i][j] == 'W')
            {
                info->map[i][j] = 0;
                info->x = info->tile_width * j + info->tile_width / 2;
                info->y = info->tile_height * i + info->tile_height / 2;
                info->view_angle = PI;
            }
            else if (info->map[i][j] == 'E')
            {
                info->map[i][j] = 0;
                info->x = info->tile_width * j + info->tile_width / 2;
                info->y = info->tile_height * i + info->tile_height / 2;
                info->view_angle = 0;
            }
            else
                info->map[i][j] = -1;
        }
    }
}

void init_info_test(char *filename, t_info *info)
{
    t_ps *ps;
    int fd;
    char *line;
    int map_start;

    ps = (t_ps *)malloc(sizeof(t_ps));
    // ft_memset(ps, 0, sizeof(t_ps)); // 동적할당에는 sizeof 쓰면 안된다고 들었는데.. 되나? ps가 아니라 t_ps라고 하면 되나?
    fd = open(filename, O_RDONLY);
    line = 0;
    map_start = 0;
    while ((get_next_line(fd, &line) || ft_strlen(line)))
    {
        map_start++;
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
        {
            map_start--;
            init_info_map_wh(line, info); // 몇줄 될지 모르니까 연결리스트 쓰면 좋을것같은데...
        }
        // parsing_map(info, ps);
        free(line);
    }
    free(line); // 또 해줘야하는건가?
    line = 0; // 안해주면 안되나?

    // printf("%d\n", map_start);
    close(fd);
    fd = open(filename, O_RDONLY);
    info->map = (char **)malloc(sizeof(char *) * info->map_height);
    while ((get_next_line(fd, &line) || ft_strlen(line)))
    {
        if (map_start <= 0)
        {
            info->map[-map_start] = (char *)malloc(info->map_width + 1);
            ft_strlcpy(info->map[-map_start], line, info->map_width + 1);
            // printf("[%s]\n", info->map[-map_start]);
        }
        map_start--;
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

    info->tile_width = info->win_width / info->map_width;
    info->tile_height = info->win_height / info->map_height;
    init_info_wall(info, ps);
    convert_map(info);

    free(ps->no);
    free(ps->so);
    free(ps->we);
    free(ps->ea);
    free(ps->s);
    free(ps);
}
