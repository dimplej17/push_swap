/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:16:09 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/13 19:41:58 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

// Check if it is not just a single number
int	check_space(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == ' ' || s[index] == '\t')
			return (1);
		index++;
	}
	return (0);
}

void	ft_errorcheck2(t_node **stack_a)
{
	if (*stack_a)
		delete_list(stack_a);
	write(1, "Error\n", 6);
}
