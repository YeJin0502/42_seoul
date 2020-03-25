			// int p1_x; // 여기부터 bres
			// int p1_y;
			// int p2_x;
			// int p2_y;
			// int dx;
			// int dy;
			// int D;
			// int hit = 0;
			// if ((posX - mapX) > (posY - mapY))
			// {
			// 	if (rayDirX < 0)
			// 	{
			// 		p2_x = mapX;
			// 		p2_y = mapY;
			// 		p1_x = mapX + rayDirX;
			// 		p1_y = mapX + rayDirY;
			// 	}
			// 	else
			// 	{
			// 		p1_x = mapX;
			// 		p1_y = mapY;
			// 		p2_x = mapX + rayDirX;
			// 		p2_y = mapX + rayDirY;
			// 	}
			// 	int yi;
			// 	dx = p2_x - p1_x;
			// 	dy = p2_y - p1_y;
			// 	yi = 1;
			// 	D = 2 * dy - dx;
			// 	while (hit == 0)
			// 	{
			// 		if (D > 0)
			// 		{
			// 			p1_y += yi;
			// 			D -= 2 * dx;
			// 		}
			// 		D += 2 * dy;
			// 		p1_x++;
			// 		if (worldMap[p1_x][p1_y] > 0)
			// 			hit = 1;
			// 	}
			// }
			// else
			// {
			// 	if (rayDirY < 0)
			// 	{
			// 		p2_x = mapX;
			// 		p2_y = mapY;
			// 		p1_x = mapX + rayDirX;
			// 		p1_y = mapX + rayDirY;
			// 	}
			// 	else
			// 	{
			// 		p1_x = mapX;
			// 		p1_y = mapY;
			// 		p2_x = mapX + rayDirX;
			// 		p2_y = mapX + rayDirY;
			// 	}
			// 	int xi;
			// 	dx = p2_x - p1_x;
			// 	dy = p2_y - p1_y;
			// 	xi = 1;
			// 	D = 2 * dx - dy;
			// 	while (hit == 0)
			// 	{
			// 		if (D > 0)
			// 		{
			// 			p1_x += xi;
			// 			D -= 2 * dy;
			// 		}
			// 		D += 2 * dx;
			// 		p1_y++;
			// 		if (worldMap[p1_x][p1_y] > 0)
			// 			hit = 1;
			// 	}
			// }
			// int EuclidDist;
			// EuclidDist = sqrt((p1_x - mapX)*(p1_x - mapX) + (p1_y - mapY)*(p1_y - mapY));
			// int perpWallDist;
			// perpWallDist = EuclidDist * (p1_x * mapX + p1_y * mapY)
			// 			/ (sqrt(p1_x*p1_x + p1_y*p1_y) * sqrt(mapX*mapX + mapY*mapY)); // 여기까지 bres
