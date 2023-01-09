/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:21:43 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/05 10:48:49 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

/**
 * @brief function that counts the lenght of a string
 * 
 * @param s is the string whose lenght we want to know
 * @return size_t return the length of the string
 */
size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

/**
 * @brief function that duplicate a strinf in an array or a list
 * 
 * @param s1 the string that we wants to duplicate
 * @return char* return the array or list where we save the copy of the string
 */
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief function that takes a list and scrolls it to the end
 * 
 * @param lst the list that we wants to scroll
 * @return t_env* return the last node of the list
 */
t_env	*lstlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
 * @brief function that mallocates a new node and sets the next one to null
 * 
 * @param content it's the current node where we are
 * @return t_env* return the new node that it mallocated
 */
t_env	*lstnew(void *content)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->current = content;
	new->next = NULL;
	return (new);
}

/**
 * @brief function that with lstlast scroll the list until the last node
 * and at the end add a new node to be mallocated and filled
 * 
 * @param lst the list where to add the new node
 * @param new the new node to be created, mallocate and fill
 */
void	lstadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	new->next = last->next;
	last->next = new;
}
