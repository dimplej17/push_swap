/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:10:45 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/16 19:27:14 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_node	*ft_copy_lst(t_node *lst)
{
	t_node	*result;
	t_node	*new;
	int		flag;

	result = NULL;
	flag = 0;
	while (lst != NULL)
	{
		if (flag == 0)
		{
			result = create_newnode(lst->num);
			flag = 1;
		}
		else
		{
			new = create_newnode(lst->num);
			add_back_node(&result, new);
		}
		lst = lst->next;
	}
	return (result);
}

void	ft_swap(long *a, long *b)
{
	long	temp;

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

void	ft_initialise_variables(t_node **copy_lst, t_node **sorted_list,
		t_node *lst)
{
	*copy_lst = ft_copy_lst(lst);
	*sorted_list = ascending_sort(*copy_lst);
}

t_node	*ft_normalise(t_node *lst)
{
	t_node	*sorted_list;
	t_node	*copy_lst;
	t_node	*current;
	t_node	*temp;
	int		count;

	ft_initialise_variables(&copy_lst, &sorted_list, lst);
	current = lst;
	while (current != NULL)
	{
		temp = sorted_list;
		count = 0;
		while (temp != NULL)
		{
			if (current->num == temp->num)
			{
				current->num = count;
				break ;
			}
			count++;
			temp = temp->next;
		}
		current = current->next;
	}
	return (delete_list(&sorted_list), lst);
}
