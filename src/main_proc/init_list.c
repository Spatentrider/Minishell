/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:21:43 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/09 13:58:53 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

// /**
//  * @brief function that counts the lenght of a string
//  * 
//  * @param s is the string whose lenght we want to know
//  * @return size_t return the length of the string
//  */
// size_t	ft_strlen(const char *s)
// {
// 	int	l;

// 	l = 0;
// 	while (s[l] != '\0')
// 		l++;
// 	return (l);
// }

// /**
//  * @brief function that duplicate a strinf in an array or a list
//  * 
//  * @param s1 the string that we wants to duplicate
//  * @return char* return the array or list where we save the copy of the string
//  */
// char	*ft_strdup(const char *s1)
// {
// 	char	*str;
// 	size_t	i;

// 	i = 0;
// 	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// /**
//  * @brief function that takes a list and scrolls it to the end
//  * 
//  * @param lst the list that we wants to scroll
//  * @return t_shell* return the last node of the list
//  */
// t_shell	*lstlast(t_shell *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->env.next != NULL)
// 		lst->env.next = lst->env.next;
// 	return (lst);
// }

// /**
//  * @brief function that mallocates a new node and sets the next one to null
//  * 
//  * @param content it's the current node where we are
//  * @return t_shell* return the new node that it mallocated
//  */
// t_shell	*lstnew(void *content)
// {
// 	t_shell	*new;

// 	new = (t_shell *)malloc(sizeof(t_shell));
// 	if (new == NULL)
// 		return (NULL);
// 	new->env.current = content;
// 	new->env.next = NULL;
// 	return (new);
// }

/**
 * @brief function that with lstlast scroll the list until the last node
 * and at the end add a new node to be mallocated and filled
 * 
 * @param lst the list where to add the new node
 * @param new the new node to be created, mallocate and fill
 */
// void	lstadd_back(t_shell **lst, t_shell *new)
// {
// 	t_shell	*last;

// 	if (lst == NULL || new == NULL)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last = lstlast(*lst);
// 	new->env.next = last->env.next;
// 	last->env.next = new->env.next;
// }

// int	ft_lstsize(t_shell *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst->env != NULL)
// 	{
// 		lst->env = lst->env.next;
// 		size++;
// 	}
// 	return (size);
// }

// int	ft_lstsize(t_list *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst != NULL)
// 	{
// 		lst = lst->next;
// 		size++;
// 	}
// 	return (size);
// }
