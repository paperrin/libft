/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:36:04 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/26 19:55:31 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

static wchar_t		*make_branch(t_rbtree_branch type)
{
	wchar_t			*branch;
	wchar_t			first;
	wchar_t			repeat;
	int				i;

	branch = (wchar_t*)malloc(sizeof(wchar_t) * (RBTREE_BRANCH_WIDTH + 1 + 1));
	if (!branch)
		return (NULL);
	branch[RBTREE_BRANCH_WIDTH + 1] = '\0';
	repeat = RBTREE_BRANCH_SPACE;
	if (type == rbtree_branch_space)
		first = RBTREE_BRANCH_SPACE;
	else if (type == rbtree_branch_vertical)
		first = RBTREE_BRANCH_VERTICAL;
	repeat = RBTREE_BRANCH_HORIZONTAL;
	if (type == rbtree_branch_cross)
		first = RBTREE_BRANCH_CROSS;
	else if (type == rbtree_branch_corner)
		first = RBTREE_BRANCH_CORNER;
	branch[0] = first;
	i = 0;
	while (branch[++i])
		branch[i] = repeat;
	return (branch);
}

static void			print_branch(t_rbtree_branch type)
{
	wchar_t		*branch;

	if ((branch = make_branch(type)))
	{
		ft_putwstr(branch);
		free(branch);
	}
}

static void			print_node(t_rbtree_node *node
		, void (*f_put)(void *content))
{
	if (node && node->color == rbtree_color_red)
		ft_putwstr(RBTREE_COLOR_NODE_RED);
	else
		ft_putwstr(RBTREE_COLOR_NODE_BLACK);
	ft_putwchar(RBTREE_BRANCH_SPACE);
	if (node && node->content)
		(*f_put)(node->content);
	else
		ft_putwstr(RBTREE_COLOR_NULL L"{null}");
	ft_putwchar(RBTREE_BRANCH_SPACE);
	ft_putwstr(RBTREE_COLOR_NODE_RESET RBTREE_COLOR_BRANCH);
	ft_putendl("");
}

static void			print_subtree(t_rbtree_node *node
		, wchar_t *prefix, int	is_tail, void (*f_put)(void *content))
{
	wchar_t		*concat_prefix_l;
	wchar_t		*concat_prefix_r;
	wchar_t		*tmp;

	ft_putwstr(prefix);
	print_branch(is_tail ? rbtree_branch_corner : rbtree_branch_cross);
	print_node(node, f_put);
	if (node)
	{
		tmp = make_branch(is_tail ? rbtree_branch_space
				: rbtree_branch_vertical);
		concat_prefix_l = ft_wstrjoin_free(
				&prefix, &tmp, 2);
		concat_prefix_r = ft_wstrdup(concat_prefix_l);
		if (node->lchild || node->rchild)
		{
			ft_putwstr(concat_prefix_l);
			print_branch(rbtree_branch_vertical);
			print_subtree(node->rchild, concat_prefix_r, 0, f_put);
			ft_putwstr(concat_prefix_l);
			print_branch(rbtree_branch_vertical);
			print_subtree(node->lchild, concat_prefix_l, 1, f_put);
		}
	}
}

void							ft_rbtree_print(t_rbtree *tree
		, void (*f_put)(void *content))
{
	wchar_t		*prefix;

	ft_putwstr(RBTREE_COLOR_GLOBAL_BASE RBTREE_COLOR_BRANCH L"\n\n");
	prefix = ft_wstrdup(L"");
	print_subtree(tree->root, prefix, 1, f_put);
	ft_putwstr(RBTREE_COLOR_GLOBAL_RESET);
	ft_putendl("\n");
}
