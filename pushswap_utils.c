/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:35 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/09 17:34:02 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// should return 0 if false and 1 if true
int	check_arg_if_int(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (!(str[count] >= 48 && str[count] <= 57))
			return (0);
		else
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
	t_node	*current;

	if (*lst == NULL)
		return ;
	current = *lst;
	*lst = NULL;
	if (current->next)
		delete_list(&(current->next));
	free(current);
}
int	check_int_limit(t_node *lst)
{
	while (lst != NULL)
	{
		if (!(lst->num >= INT_MIN && lst->num <= INT_MAX))
			return (0);
		lst = lst->next;
	}
	return (1);
}
// returns 0 is duplicates are found
int	check_duplicate(t_node *lst)
{
	int	temp;

	while (lst != NULL)
	{
		temp = lst->num;
		while (lst != NULL)
		{
			if (temp == lst->num)
				return (0);
			lst = lst->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	ft_sqroot(int n)
{
	int	temp;
	int	guess;

	if (n == 1)
		return (1);
	guess = 1;
	while (guess <= (n / 2))
	{
		temp = (guess + (n / guess)) / 2;
		if ((temp * temp) > n)
			guess++;
		else
		{
			if (((temp + 1) * (temp + 1)) > n)
				return (temp);
			guess++;
		}
	}
	return (guess); // is this okay?
}

int	ft_biggestN(t_node *lst)
{
	int temp;

	temp = lst->num;
	while (lst != NULL)
	{
		if (temp > (lst->num))
			temp = lst->num;
		lst = lst->next;
	}
	return (temp);
}