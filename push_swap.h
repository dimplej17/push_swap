/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:16:36 by djanardh          #+#    #+#             */
/*   Updated: 2025/05/17 19:15:02 by djanardh         ###   ########.fr       */
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
	long			num;
	struct s_node	*next;
}					t_node;
int					is_all_whitespace(char *str);
long				ft_atoi_long(char *str);
int					check_space(char *s);
int					ps_lstsize(t_node *lst);
void				ps_lstadd_front(t_node **lst, t_node *new);
int					check_arg_if_int(char *str);
t_node				*create_newnode(int n);
void				add_back_node(t_node **lst, t_node *new);
void				delete_list(t_node **lst);
int					check_int_limit(t_node *lst);
int					check_duplicate(t_node *lst);
int					is_sorted(t_node *lst);
int					handle_argument(char *arg, t_node **stack_a);
t_node				*ft_errorcheck3(t_node **stack_a);
t_node				*ft_errorcheck1(char *s, t_node **stack_a);
void				ft_errorcheck2(t_node **stack_a);
int					ft_sqroot(int n);
int					ft_biggest_num_pos(t_node *lst);
int					ft_biggest_num(t_node *lst);
void				ft_swap(long *a, long *b);
t_node				*ascending_sort(t_node *lst);
void				ft_initialise_variables(t_node **copy_lst,
						t_node **sorted_list, t_node *lst);
t_node				*ft_normalise(t_node *lst);
void				part2_ksort(t_node **stack_a, t_node **stack_b);
void				part3_ksort(t_node **stack_a, t_node **stack_b);
void				part1_ksort(t_node **stack_a, t_node **stack_b);
void				k_sort(t_node **stack_a);
int					push_a(t_node **stack_a, t_node **stack_b);
int					push_b(t_node **stack_b, t_node **stack_a);
int					rotate_a(t_node **stack_a);
int					rotate_b(t_node **stack_b);
int					reverse_rotate_b(t_node **stack_b);
int					swap_a(t_node **stack_a);
int					reverse_rotate_a(t_node **stack_a);
int					find_min_pos(t_node *stack);
void				small5(t_node **stack_a, t_node **stack_b);
void				sort3_helper(int flag, t_node **stack_a);
void				sort_3(t_node **stack_a);
void				ft_smallswaps(t_node **stack_a);

#endif