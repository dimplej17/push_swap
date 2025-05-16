/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:35 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/12 19:50:52 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ps_lstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	check_arg_if_int(char *str)
{
	int	count;

	if (!str || !str[0])
		return (0);
	count = 0;
	if (str[0] == '-' || str[0] == '+')
		count++;
	if (!str[count])
		return (0);
	while (str[count])
	{
		if (str[count] < '0' || str[count] > '9')
			return (0);
		count++;
	}
	return (1);
}

t_node	*create_newnode(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = n;
	new_node->next = NULL;
	return (new_node);
}

void	add_back_node(t_node **lst, t_node *new)
{
	t_node	*current;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

void	delete_list(t_node **lst)
{
	t_node	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
