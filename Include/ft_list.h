/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:20:16 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/17 04:16:57 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

t_list				*ft_lstnew(void const *content, size_t len);
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *list, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **list, void (*del)(void *, size_t));
void				ft_lstdel(t_list **list, void (*del)(void *, size_t));
void				ft_lstadd(t_list **list, t_list *new);
t_list				*ft_list_at(t_list *list, unsigned int nbr);
t_list				*ft_list_at(t_list *list, unsigned int nbr);
t_list				*ft_list_find_last(t_list *list);
void				ft_list_push_back(t_list **list, void *data, size_t len);
void				ft_list_push_front(t_list **list, void *data, size_t len);
t_list				*ft_list_push_param(int argc, char **argv);
void				ft_list_reverse(t_list **begin_list);
int					ft_list_size(t_list *list);
void				ft_list_sort(t_list **begin_list);

t_point				*ft_t_point_create(int x, int y);
void				ft_t_point_free(t_point *pt);

t_complex			ft_t_complex_init(double reel, double i);
#endif
