#include "push_swap.h"

void	r_both(t_list **a, t_list **b, t_list *cheapest)
{
	while(*a != cheapest->target && *b != cheapest)
		rr(a, b, 0);
	set_current_pos(*a);
	set_current_pos(*b);
}

void	rr_both(t_list **a, t_list **b, t_list *cheapest)
{
	while(*a != cheapest->target && *b != cheapest)
		rrr(a, b, 0);
	set_current_pos(*a);
	set_current_pos(*b);
}

void    end_rotation(t_list **stack, t_list *cheapest, char name)
{
	while(*stack != cheapest)
	{
		if(name == 'a')
		{
			if(cheapest->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if(name == 'b')
		{
			if(cheapest->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	move_nodes(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = return_cheapest(*b);
	if(cheapest->above_median && cheapest->target->above_median)
		r_both(a, b, cheapest);
	else if(!(cheapest->above_median) && !(cheapest->target->above_median))
		rr_both(a, b, cheapest);
	end_rotation(b, cheapest, 'b');
	end_rotation(a, cheapest->target, 'a');
	pa(a, b, 0);
}

void	push_swap(t_list **a, t_list **b)
{
    t_list  *smallest;
    int len;

    len = stack_len(*a);
    if(len == 5)
        sort_five(a, b);
    else
    {
        while (len-- > 3)
            pb(b, a, 0);
    }
    mini_sort(a);
    while(*b)
    {
        init_nodes(*a, *b);
        move_nodes(a, b);
    }
	set_current_pos(*a);
	smallest = smallest_node(*a);
	if(smallest->above_median)
	{
		while(*a != smallest)
			ra(a, 0);
	}
	else
	{
		while(*a != smallest)
			rra(a, 0);
	}	
}
