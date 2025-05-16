/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:10:35 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/12 20:15:13 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	int		temp;
	t_node	*outer;
	t_node	*inner;

	outer = lst;
	while (outer != NULL)
	{
		temp = outer->num;
		inner = outer->next;
		while (inner != NULL)
		{
			if (temp == inner->num)
				return (0);
			inner = inner->next;
		}
		outer = outer->next;
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
	return (guess);
}

int	ft_biggest_num_pos(t_node *lst)
{
	int		temp;
	t_node	*current;
	int		pos;

	pos = 0;
	current = lst;
	temp = current->num;
	while (current != NULL)
	{
		if (temp < (current->num))
			temp = current->num;
		current = current->next;
	}
	while (lst != NULL)
	{
		if (lst->num == temp)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (pos);
}

int	ft_biggest_num(t_node *lst)
{
	int		temp;
	t_node	*current;

	current = lst;
	temp = current->num;
	while (current != NULL)
	{
		if (temp < (current->num))
			temp = current->num;
		current = current->next;
	}
	return (temp);
}
