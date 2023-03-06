/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waste_collector_free_funcs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:54:19 by lorbke            #+#    #+#             */
/*   Updated: 2023/02/21 19:59:24 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // free

/*
* This file contains a set of often needed free functions 
* for common data structures like string arrays and so on.
*/

/**
 * It takes a pointer to a pointer to a char, 
 * and frees all the strings in the array, and then frees
 * the array itself
 * 
 * @param str_arr_void This is the pointer to the array of strings.
 */
void	ww_free_str_arr(void *str_arr_void)
{
	char	**str_arr;
	char	**temp;

	str_arr = (char **)str_arr_void;
	temp = str_arr;
	while (*str_arr)
	{
		free(*str_arr);
		str_arr++;
	}
	free(temp);
}
