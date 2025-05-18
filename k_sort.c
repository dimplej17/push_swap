/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:10:03 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/16 17:10:51 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	part1_ksort(t_node **stack_a, t_node **stack_b)
{
	int	decision_line;

	decision_line = ft_sqroot(ps_lstsize(*stack_a));
	while (*stack_a != NULL)
	{
		if (((*stack_a)->num) <= ps_lstsize(*stack_b))
		{
			if (push_b(stack_b, stack_a))
				ft_putstr_fd("pb\n", 1);
			if (rotate_b(stack_b))
				ft_putstr_fd("rb\n", 1);
		}
		else if (((*stack_a)->num) <= (decision_line + ps_lstsize(*stack_b)))
		{
			if (push_b(stack_b, stack_a))
				ft_putstr_fd("pb\n", 1);
		}
		else
		{
			if (rotate_a(stack_a))
				ft_putstr_fd("ra\n", 1);
		}
	}
}

void	part3_ksort(t_node **stack_a, t_node **stack_b)
{
	int	biggest_num;
	int	pos_biggest_num;
	int	size;

	size = ps_lstsize(*stack_b);
	biggest_num = ft_biggest_num(*stack_b);
	pos_biggest_num = ft_biggest_num_pos(*stack_b);
	if (pos_biggest_num <= size / 2)
	{
		while ((*stack_b)->num != biggest_num)
		{
			if (rotate_b(stack_b))
				ft_putstr_fd("rb\n", 1);
		}
	}
	else
	{
		while ((*stack_b)->num != biggest_num)
			if (reverse_rotate_b(stack_b))
				ft_putstr_fd("rrb\n", 1);
	}
	if (push_a(stack_a, stack_b))
		ft_putstr_fd("pa\n", 1);
}

void	part2_ksort(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b != NULL)
		part3_ksort(stack_a, stack_b);
}

void	k_sort(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	part1_ksort(stack_a, &stack_b);
	part2_ksort(stack_a, &stack_b);
	delete_list(&stack_b);
}
