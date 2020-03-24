#ifndef HEADER_H
#define HEADER_H

# define w 640
# define h 480
# define mapWidth 24
# define mapHeight 24

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_graphic
{
	void		*mlx;
	void		*win;
}				t_gra;

typedef struct	s_pos
{
	int			x;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldTime;
}				t_pos;

typedef struct	s_dda
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			color;
	int			tmp_y;
}				t_dda;

void			start(t_gra *a, t_pos *p);
void			cal_dda(t_gra *a, t_pos *p);
void			cal_dda_2(t_gra *a, t_pos *p, t_dda *dda);
void			cal_dda_2_1(t_pos *p, t_dda *dda);
void			cal_dda_2_2(t_gra *a, t_pos *p, t_dda *dda);
void			cal_dda_2_3(t_gra *a, t_pos *p, t_dda *dda);


#endif
