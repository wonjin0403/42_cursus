#include "cub3d.h"

t_sprite_data	*lstnew(double x, double y, double distance)
{
	t_sprite_data	*ans;

	ans = (t_sprite_data *)malloc(sizeof(t_sprite_data));
	if (!ans)
		return (0);
	ans->x = x;
	ans->y = y;
    ans->distance = distance;
    ans->before = NULL;
    ans->next = NULL;
	return (ans);
}

void	lstadd_front(t_sprite_data **lst, t_sprite_data *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		(*lst)->before = new;
        new->next = *lst;
		*lst = new;
	}
}

void	lstclear(t_sprite_data **ptr, t_sprite_data *node)
{
	t_sprite_data	*now;

	if(!node)
		return ;
    if(node->before == NULL && node->next == NULL) 
        *ptr = NULL;
    else
    {
        if(node->before == NULL)
            *ptr = node->next;
	    else
            node->before->next = node->next;
        node->next->before = node->before;
    }
    free(node);
    node = NULL;
}

int     search(t_data *data, double x, double y)
{
    t_sprite_data *node;

    node = data->ptr;
    while(node)
    {
        if(node->x == x && node->y == y)
            return (1);
        node = node->next;
    }
    return (0);
}

void    add_sprite(t_data *data, int x, int y)
{
    t_sprite_data *new;
    
    if(search(data, x + 0.5, y + 0.5) == 1)
        return ;
    //printf("sprite %f %f, pos  %f, %f\n", (double)x, (double)y, data->input.pos_x, data->input.pos_y);
    new = lstnew(x + 0.5, y + 0.5, distance(x, y, data->input.pos_x, data->input.pos_y));
    lstadd_front(&(data->ptr), new);
}

t_sprite_data    *max_sprite(t_sprite_data **ptr)
{
    t_sprite_data *max;    
    t_sprite_data *now;
    
    now = *ptr;
    max = *ptr;
    while(now->next)
    {
        if(max->distance < now->distance)
            max = now;
        now = now->next;
    }
    return (max);
}

void    cal_sprite(t_data *data, t_draw_sprite *sprite_data, t_sprite_data *max)
{
    double invDet;
    double spriteX;
    double spriteY;
    double transformX;
    double transformY;

    invDet = 1.0 / (data->input.planeX * data->input.dirY\
                        - data->input.dirX * data->input.planeY);
    spriteX = (double)max->x - data->input.pos_x;
    spriteY = (double)max->y - data->input.pos_y;
    transformX = invDet * ((data->input.dirY) * spriteX - (data->input.dirX) * spriteY);
    transformY = invDet * (-(data->input.planeY) * spriteX + (data->input.planeX) * spriteY);
    sprite_data->spriteScreenX = (int)((data->input.width / 2) * (1 + transformX / transformY));
    sprite_data->spriteHeight = abs((int)(data->input.height / (transformY)));
    sprite_data->spriteWidth = abs((int)(data->input.height / (transformY)));
}

void    draw_sprite(t_data *data, double *dist_arr)
{
    t_sprite_data   *max;
    t_mlx_data      text;
    t_draw_sprite   sprite_data;
    int             x;
    double          texX;
      
    while(data->ptr)
    {
        max = max_sprite(&(data->ptr));
        cal_sprite(data, &sprite_data, max);
        sprite_data.drawStartY = -sprite_data.spriteHeight / 2 + data->input.height / 2;
        if(sprite_data.drawStartY < 0)
            sprite_data.drawStartY = 0;
        sprite_data.drawEndY = sprite_data.spriteHeight / 2 + data->input.height / 2;
        if(sprite_data.drawEndY >= data->input.height)
            sprite_data.drawEndY = data->input.height - 1;
        sprite_data.drawStartX = -sprite_data.spriteWidth / 2 + sprite_data.spriteScreenX;
        if(sprite_data.drawStartX < 0)
            sprite_data.drawStartX = 0;
        sprite_data.drawEndX = sprite_data.spriteWidth / 2 + sprite_data.spriteScreenX;
        if(sprite_data.drawEndX >= data->input.width)
            sprite_data.drawEndX = data->input.width - 1;
        lstclear(&(data->ptr), max);
        x = sprite_data.drawStartX;
        while(++x < sprite_data.drawEndX)
        {
            if(dist_arr[x] <= max->distance)
                continue;
            else
                printf("dist %f %f\n", dist_arr[x], max->distance);
            text = data->texture.sprite;
            texX = (double)text.x * ((double)(x - sprite_data.drawStartX) / (double)(sprite_data.drawEndX - sprite_data.drawStartX + 1));
            verLine(&(data->img_data), &text, 0, data->input.width - x, sprite_data.drawStartY, sprite_data.drawEndY, texX);
        }
    }
}