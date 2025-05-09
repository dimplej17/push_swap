/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:44:05 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/09 18:37:54 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	k_sort(t_node *stack_a)
{
	int		decision_line;
	t_node	*stack_b;
	int		biggest_num_b;

	stack_b = NULL;
	decision_line = ft_sqroot(ft_lstsize(stack_a));
	while (stack_a != NULL)
	{
		if ((stack_a->num) <= ft_lstsize(stack_b))
		{
			push_b(&stack_b);
			rotate_b(&stack_b);
		}
		else if ((stack_a->num) <= (decision_line + ft_lstsize(stack_b)))
			push_b(&stack_b);
		else
			rotate_a(&stack_a);
	}
	if (stack_a == NULL)
	{
		biggest_num_b = ft_biggestN(stack_b);
		// rotate it to the top(rotate the shortest way,
		// so If its in the lower half move it down not up)
		push_a(stack_a);
	}
}

void	ft_normalise(t_node *lst)
{
	
}

int	main(int argc, char *argv[])
{
	int		count;
	int		arg_pos;
	int		num;
	t_node	*stack_a;
	t_node	*new;

	if (argc < 2)
		return (0);
	arg_pos = 1;
	count = 0;
	while (arg_pos < argc)
	{
		if (check_arg_if_int(argv[count]))
		{
			num = ft_atoi(argv[count]);
			if (arg_pos == 1)
				stack_a = create_newnode(num);
			else
			{
				new = create_newnode(num);
				add_back_node(&stack_a, new);
			}
		}
		else
		{
			if (stack_a)
				delete_list(&stack_a);
			write(1, "Error\n", 6);
			return (0);
		}
		arg_pos++;
		count++;
	}
	if (check_int_limit(stack_a))
	{
		if (check_duplicate(stack_a))
		{
			if (ft_lstsize(stack_a) == 1)
				return (0);
			ft_normalise(stack_a);
		}
		else
		{
			delete_list(&stack_a);
			write(1, "Error\n", 6);
			return (0);
		}
	}
	else
	{
		delete_list(&stack_a);
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
