#include "cub3d.h"

t_queue     *push(t_queue *queue, int x, int y)
{
    t_queue *new_node;

    if(!(new_node = (t_queue *)malloc(sizeof(t_queue))))
        return (0);
    new_node->x = x;
    new_node->y = y;
    if (queue)
        new_node->next = queue;
    else
        new_node->next = NULL;
    queue = new_node;
    return (queue);
}

t_queue     *pop(t_queue *queue, int *x, int *y)
{
    t_queue *now;
    t_queue *before;
    int     cnt;

    cnt = 0;
    before = NULL;
    now = queue;
    while(queue && now->next)
    {
        before = now;
        now = now->next;
        cnt++;
    }
    *x = (now) ? now->x : 0;
    *y = (now) ? now->y : 0;
    if (before)
        before->next = NULL;
    free(now);
    if(cnt == 0)
        queue = NULL;
    return (queue);
}

size_t      empty(t_queue *queue)
{
    size_t  len;

    if(!queue)
        return (0);
    len = 1;
    //printf("%p\n", queue->next);
    while(queue->next)
    {
        queue = queue->next;
        len++;
    }
    //printf("222\n");
    return (len);
}

t_queue     *remove_queue(t_queue *queue)
{
    t_queue *next;

    while(queue)
    {
        next = queue->next;
        free(queue);
        queue = next;
    }
    queue = NULL;
    return (queue);
}