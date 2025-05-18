/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:16:09 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/17 19:28:46 by djanardh         ###   ########.fr       */
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
	write(2, "Error\n", 6);
}

long	ft_atoi_long(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_all_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
