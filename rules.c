/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:10:26 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/12 20:14:38 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// pa (push a): Take the first element at the top of b and put it at the top
// of a. Do nothing if b is empty.
int	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	t_node	*new;

	if (*stack_b == NULL)
		return (0);
	new = create_newnode((*stack_b)->num);
	if (!new)
		return (0);
	ps_lstadd_front(stack_a, new);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(temp);
	return (1);
}

// pb (push b): Take the first element at the top of a and put it at the top
// of b. Do nothing if a is empty.
int	push_b(t_node **stack_b, t_node **stack_a)
{
	t_node	*temp;
	t_node	*new;

	if (*stack_a == NULL)
		return (0);
	new = create_newnode((*stack_a)->num);
	if (!new)
		return (0);
	ps_lstadd_front(stack_b, new);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(temp);
	return (1);
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	rotate_a(t_node **stack_a)
{
	t_node	*temp;
	t_node	*current;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	current = *stack_a;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	return (1);
}

// rb (rotate b): Shift up all elements of stack b by 1. The first element
// becomes the last one.
int	rotate_b(t_node **stack_b)
{
	t_node	*temp;
	t_node	*current;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	current = *stack_b;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	return (1);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last
// element becomes the first one.
int	reverse_rotate_b(t_node **stack_b)
{
	t_node	*copy_address_head;
	t_node	*current;
	t_node	*copy_address_lastnode;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (0);
	current = *stack_b;
	copy_address_head = *stack_b;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	copy_address_lastnode = current->next;
	current->next = NULL;
	copy_address_lastnode->next = copy_address_head;
	*stack_b = copy_address_lastnode;
	return (1);
}
