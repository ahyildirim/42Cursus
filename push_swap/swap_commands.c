#include "push_swap.h"

static void swap(t_list **a)
{
    int len;

    len = stack_len(*a);
    if(*a == NULL || a == NULL || len == 1)
        return ;
    *a = (*a)->next;
	(*a)->prev->prev = (*a);
	(*a)->prev->next = (*a)->next;
	if((*a)->next)
	    (*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
}

void sa(t_list **a, int checker)
{
    swap(a);
    if(!checker)
        write(1, "sa\n", 3);
}

void sb(t_list **b, int checker)
{
    swap(b);
    if(!checker)
        write(1, "sb\n", 3);
}

void ss(t_list **a, t_list **b, int checker)
{
    swap(a);
    swap(b);
    if(!checker)
        write(1, "ss\n", 3);
}