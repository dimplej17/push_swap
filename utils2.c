#include "libft.h"
#include "push_swap.h"

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
	int	temp;

	temp = lst->num;
	while (lst != NULL)
	{
		if (temp > (lst->num))
			temp = lst->num;
		lst = lst->next;
	}
	return (temp);
}

t_node	*ft_copy_lst(t_node *lst)
{
	t_node *result;

	if (arg_pos == 1)
		stack_a = create_newnode(num);
	else
	{
		new = create_newnode(num);
		add_back_node(&stack_a, new);
	}

	return (result);
}