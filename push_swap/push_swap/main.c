#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
	if(ac == 1)
		return (1);
    else if(ac == 2)
        av = ft_split(av[1], ' ');
    initialize_stack(&a, &av[1], ac == 2);
    if(!is_sorted(a))
    {
        if(stack_len(a) == 2)
            sa(&a, 0);
        else if(stack_len(a) == 3)
            mini_sort(&a);
        else
            push_swap(&a, &b);
    }
	free_stack(&a);
}