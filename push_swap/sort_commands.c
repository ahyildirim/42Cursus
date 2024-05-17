#include "push_swap.h"

int is_sorted(t_list *a)
{
    if(a == NULL)
        return (1);
    while(a->next)
    {
        if(a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}

static t_list *find_highest(t_list *a)
{
    int highest;
    t_list *highest_node;

    if(a == NULL)
        return (NULL);
    highest = INT_MIN;
    while(a)
    {
        if(a->value > highest)
        {
            highest = a->value;
            highest_node = a;
        }
        a = a->next;
    }
    return (highest_node);
}

void mini_sort(t_list **a)
{
    t_list *highest;

    highest = find_highest(*a);
    if(*a == highest)
        ra(a, 0);
    else if((*a)->next == highest)
        rra(a, 0);
    if((*a)->value > (*a)->next->value)
        sa(a, 0);
}

void	sort_five(t_list **a, t_list **b)
{
	
	while(stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		end_rotation(a, smallest_node(*a), 'a');
		pb(b, a, 0);
	}
}