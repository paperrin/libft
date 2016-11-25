/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:42:06 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/25 16:53:00 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H

# include <string.h>
# include <stdlib.h>

typedef enum		e_rbtree_color
{
	rbtree_color_black,
	rbtree_color_red
}					t_rbtree_color;

typedef struct s_rbtree_node	t_rbtree_node;
struct				s_rbtree_node
{
	t_rbtree_color	color;
	t_rbtree_node	*parent;
	t_rbtree_node	*lchild;
	t_rbtree_node	*rchild;
	void			*content;
	size_t			content_size;
};

typedef struct		s_rbtree
{
	t_rbtree_node	*root;
	int				(*cmp_f)(void*, void*);
}					t_rbtree;

t_rbtree			ft_rbtree_new(int (*cmp_f)(void*, void*));
t_rbtree_node		*ft_rbtree_add(t_rbtree *tree, void *content
		, size_t content_size);

#endif
