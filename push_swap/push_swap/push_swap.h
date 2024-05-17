#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list
{
    int             value;
    int             current_pos;
    int             final_index;
    int             cost;
    int             above_median;
    int             cheapest;
    struct s_list   *next;
    struct s_list   *prev;
    struct s_list   *target;

}                   t_list;

int rep_error(t_list *a, int nbr);
int syntax_error(char *av);
int is_sorted(t_list *a);
int stack_len(t_list *a);
long	ft_atoi(const char *str);
void initialize_stack(t_list **a, char **av, int flag);
void mini_sort(t_list **a);
t_list	*smallest_node(t_list *stack);
void free_stack(t_list **a);
void error_free(t_list **a, char **av, int flag);
void free_av(char **av);
void sa(t_list **a, int checker);
void sb(t_list **b, int checker);
void ss(t_list **a, t_list **b, int checker);
void ra(t_list **a, int checker);
void rb(t_list **b, int checker);
void rr(t_list **a, t_list **b, int checker);
void	rra(t_list **a, int checker);
void	rrb(t_list **b, int checker);
void	rrr(t_list **a, t_list **b, int checker);
void	pa(t_list **a, t_list **b, int checker);
void	pb(t_list **b, t_list **a, int checker);
void push_swap(t_list **a, t_list **b);
void init_nodes(t_list *a, t_list *b);
void mini_sort(t_list **a);
void	sort_five(t_list **a, t_list **b);
void    end_rotation(t_list **stack, t_list *cheapest, char name);
void	set_current_pos(t_list *stck);
t_list	*return_cheapest(t_list *stack);
t_list *find_last_node(t_list *a);
char	**ft_split(char *str, char separator);

#endif


