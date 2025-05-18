/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:16:46 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/17 19:00:03 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// sa(swap a) : Swap the first 2 elements at the top of stack a.Do nothing if
// there is only one element or none.
int	swap_a(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	long	temp;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	first = *stack_a;
	second = (*stack_a)->next;
	temp = first->num;
	first->num = second->num;
	second->num = temp;
	return (1);
}

int	reverse_rotate_a(t_node **stack_a)
{
	t_node	*copy_address_head;
	t_node	*current;
	t_node	*copy_address_lastnode;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	current = *stack_a;
	copy_address_head = *stack_a;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	copy_address_lastnode = current->next;
	current->next = NULL;
	copy_address_lastnode->next = copy_address_head;
	*stack_a = copy_address_lastnode;
	return (1);
}
