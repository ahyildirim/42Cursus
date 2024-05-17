#include "push_swap.h"

void	set_current_pos(t_list *stck)
{
	int i;
	int center;

	i = 0;
	if(stck == NULL)
		return ;
	center = stack_len(stck) / 2;
	while(stck)
	{
		stck->current_pos = i;
		if(i <= center)
			stck->above_median = 1;
		else
			stck->above_median = 0;
		stck = stck->next;
		i++;
	}
}

void	set_target_node(t_list *a, t_list *b)
{
	t_list	*current_node_a;
	t_list	*target_node;
	long	min;

	while(b)
	{
		min = LONG_MAX;
		current_node_a = a;
		while(current_node_a)
		{
			if(current_node_a->value > b->value
				&& current_node_a->value < min)
			{
				min = current_node_a->value;
				target_node = current_node_a;
			}
			current_node_a = current_node_a->next;
		}
		if(min == LONG_MAX)
			b->target = smallest_node(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	set_price(t_list *a, t_list *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while(b)
	{
		b->cost = b->current_pos;
		if(b->above_median == 0)
			b->cost = b_len - (b->current_pos);
		if(b->target->above_median == 1)
			b->cost += b->target->current_pos;
		else
			b->cost += a_len - (b->target->current_pos);
		b = b->next;
	}
}

void	set_cheapest(t_list *stack)
{
	long	min;
	t_list	*cheapest_node;

	if(stack == NULL)
		return ;
	min = LONG_MAX;
	while(stack)
	{
		if(stack->cost < min)
		{
			min = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void init_nodes(t_list *a, t_list *b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
