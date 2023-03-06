/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waste_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:14:34 by lorbke            #+#    #+#             */
/*   Updated: 2023/02/28 18:37:07 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "waste_wizard.h" // t_waste
#include <stdlib.h> // NULL, malloc, free
#include <sys/errno.h> // errno
#include <unistd.h> // write

t_waste	**waste_init(void);

static t_waste	*create_waste(void *alloc, void (*func_free)(void *))
{
	t_waste	*new;

	new = malloc(sizeof(t_waste));
	if (new == NULL)
	{
		ww_free_all_waste();
		exit(errno);
	}
	new->alloc = alloc;
	if (func_free == NULL)
		new->func_free = &free;
	else
		new->func_free = func_free;
	new->next = NULL;
	return (new);
}

static t_waste	*append_waste(t_waste *main, t_waste *append)
{
	t_waste	*tmp;

	if (main == NULL)
		return (append);
	tmp = main;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = append;
	return (main);
}

void	ww_add_waste(void *alloc, void (*func_free)(void *))
{
	t_waste	*new;
	t_waste	**waste;

	new = create_waste(alloc, func_free);
	waste = waste_init();
	*waste = append_waste(*waste_init(), new);
}

void	*ww_malloc_and_add(size_t size, size_t count)
{
	void	*alloc;

	alloc = malloc(size * count);
	if (alloc == NULL)
	{
		ww_free_all_waste();
		exit(errno);
	}
	ww_add_waste(alloc, free);
	return (alloc);
}

void	ww_free_all_waste(void)
{
	t_waste	*waste;
	t_waste	*temp;

	waste = ww_get_waste();
	while (waste != NULL)
	{
		temp = waste;
		waste = waste->next;
		temp->func_free(temp->alloc);
		free(temp);
	}
	*waste_init() = NULL;
}
