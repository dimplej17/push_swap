/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:44:05 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/10 18:54:47 by djanardh         ###   ########.fr       */
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

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
t_node	*ascending_sort(t_node *lst)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = lst;
	while (temp1->next != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->num > temp2->num)
				ft_swap(&temp1->num, &temp2->num);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (lst);
}

t_node	*ft_normalise(t_node *lst)
{
	t_node	*sorted_list;
	int		count;
	t_node	*result;
	t_node	*copy_lst;
	t_node	*copy_sorted_list;

	result = lst;
	copy_lst = ft_copy_lst(lst);
	sorted_list = ascending_sort(copy_lst);
	copy_sorted_list = ft_copy_lst(sorted_list);
	while (lst != NULL)
	{
		count = 0;
		sorted_list = copy_sorted_list;
		while (sorted_list != NULL)
		{
			if (lst->num == sorted_list->num)
			{
				lst->num = count;
				break ;
			}
			count++;
			sorted_list = sorted_list->next;
		}
		lst = lst->next;
	}
	return (result);
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
			k_sort(ft_normalise(stack_a));
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
