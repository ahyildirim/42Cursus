#include "push_swap.h"

static void rotate(t_list **a)
{
    t_list *last_node;
    int len;

    len = stack_len(*a);
    if(*a == NULL || a == NULL || len == 1)
        return ;
    last_node = find_last_node(*a);
    last_node->next = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

static void rev_rotate(t_list **a)
{
    t_list *last_node;
    int len;

    len = stack_len(*a);
    if(*a == NULL || a == NULL || len == 1)
        return ;
    last_node = find_last_node(*a);
    last_node->prev->next = NULL;
    last_node->next = *a;
    last_node->prev = NULL;
    *a = last_node;
    last_node->next->prev = last_node;
}

void ra(t_list **a, int checker)
{
    rotate(a);
    if(!checker)
        write(1, "ra\n", 3);
}

void rb(t_list **b, int checker)
{
    rotate(b);
    if(!checker)
        write(1, "rb\n", 3);
}

void rr(t_list **a, t_list **b, int checker)
{
    rotate(a);
    rotate(b);
    if(!checker)
        write(1, "rr\n", 3);
}

void	rra(t_list **a, int checker)
{
	rev_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int checker)
{
	rev_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int checker)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
