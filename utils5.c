/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:45:15 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/17 19:53:14 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort3_helper(int flag, t_node **stack_a)
{
	if (flag == 1)
	{
		if (swap_a(stack_a))
			ft_putstr_fd("sa\n", 1);
	}
	else if (flag == 2)
	{
		if (swap_a(stack_a))
			ft_putstr_fd("sa\n", 1);
		if (reverse_rotate_a(stack_a))
			ft_putstr_fd("rra\n", 1);
	}
	else if (flag == 3)
	{
		if (swap_a(stack_a))
			ft_putstr_fd("sa\n", 1);
		if (rotate_a(stack_a))
			ft_putstr_fd("ra\n", 1);
	}
}

void	sort_3(t_node **stack_a)
{
	long	x;
	long	y;
	long	z;

	x = (*stack_a)->num;
	y = (*stack_a)->next->num;
	z = (*stack_a)->next->next->num;
	if (x > y && y < z && x < z)
		sort3_helper(1, stack_a);
	else if (x > y && y > z)
		sort3_helper(2, stack_a);
	else if (x > y && y < z && x > z)
	{
		if (rotate_a(stack_a))
			ft_putstr_fd("ra\n", 1);
	}
	else if (x < y && y > z && x < z)
		sort3_helper(3, stack_a);
	else if (x < y && y > z && x > z)
	{
		if (reverse_rotate_a(stack_a))
			ft_putstr_fd("rra\n", 1);
	}
}

int	find_min_pos(t_node *stack)
{
	int		pos;
	int		min;
	int		i;
	t_node	*tmp;

	pos = 0;
	min = stack->num;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	small5(t_node **stack_a, t_node **stack_b)
{
	int	min_pos;

	while (ps_lstsize(*stack_a) > 3)
	{
		min_pos = find_min_pos(*stack_a);
		while (min_pos != 0)
		{
			if (min_pos <= ps_lstsize(*stack_a) / 2)
			{
				if (rotate_a(stack_a))
					ft_putstr_fd("ra\n", 1);
			}
			else if (reverse_rotate_a(stack_a))
				ft_putstr_fd("rra\n", 1);
			min_pos = find_min_pos(*stack_a);
		}
		push_b(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		if (push_a(stack_a, stack_b))
			ft_putstr_fd("pa\n", 1);
	}
}

void	ft_smallswaps(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (ps_lstsize(*stack_a) == 2)
	{
		if (swap_a(stack_a))
			ft_putstr_fd("sa\n", 1);
	}
	else if (ps_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else if (ps_lstsize(*stack_a) == 5 || ps_lstsize(*stack_a) == 4)
		small5(stack_a, &stack_b);
	delete_list(&stack_b);
}
