/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:16:36 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/10 18:51:30 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}					t_node;
int					check_arg_if_int(char *str);
t_node				*create_newnode(int n);
void				add_back_node(t_node **lst, t_node *new);
void				delete_list(t_node **lst);
int					check_int_limit(t_node *lst);
int					check_duplicate(t_node *lst);
int					ft_sqroot(int n);
int					ft_biggestN(t_node *lst);

#endif