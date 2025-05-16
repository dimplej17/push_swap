/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:44:05 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/16 17:12:08 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_node	*ft_errorcheck1(char *s, t_node **stack_a)
{
	int		num;
	t_node	*new;

	if (!check_arg_if_int(s))
		return (ft_errorcheck2(stack_a), NULL);
	num = ft_atoi(s);
	new = create_newnode(num);
	if (!new)
		return (delete_list(stack_a), NULL);
	if (*stack_a == NULL)
		*stack_a = new;
	else
		add_back_node(stack_a, new);
	return (*stack_a);
}

int	is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_node	*ft_errorcheck3(t_node **stack_a)
{
	if (!check_int_limit(*stack_a))
	{
		delete_list(stack_a);
		write(1, "Error\n", 6);
		return (NULL);
	}
	if (!check_duplicate(*stack_a))
	{
		delete_list(stack_a);
		write(1, "Error\n", 6);
		return (NULL);
	}
	if (ps_lstsize(*stack_a) == 1 || ps_lstsize(*stack_a) == 0)
		return (delete_list(stack_a), NULL);
	if (is_sorted(*stack_a))
		return (NULL);
	*stack_a = ft_normalise(*stack_a);
	k_sort(stack_a);
	return (*stack_a);
}

int	handle_argument(char *arg, t_node **stack_a)
{
	char	**string_ip;
	int		i;

	if (check_space(arg) == 0)
		return (ft_errorcheck1(arg, stack_a) != NULL);
	string_ip = ft_split(arg, ' ');
	if (!string_ip)
		return (0);
	i = 0;
	while (string_ip[i])
	{
		if (!ft_errorcheck1(string_ip[i], stack_a))
			return (ft_free_memory(string_ip, i), 0);
		i++;
	}
	ft_free_memory(string_ip, i);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		arg_pos;
	t_node	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	arg_pos = 1;
	while (arg_pos < argc)
	{
		if (!handle_argument(argv[arg_pos], &stack_a))
			return (0);
		arg_pos++;
	}
	if (!(ft_errorcheck3(&stack_a)))
		return (0);
	delete_list(&stack_a);
	return (0);
}

// void	checkleaks(void)
// {
// 	system("leaks push_swap");
// }
// atexit(&checkleaks);
