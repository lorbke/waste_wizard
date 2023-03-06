/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waste_collector_obj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:18:46 by lorbke            #+#    #+#             */
/*   Updated: 2023/02/20 21:27:12 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "waste_wizard.h" // t_waste
#include <stdlib.h> // NULL

t_waste	**wizard_init(void)
{
	static t_waste	*waste = NULL;

	return (&waste);
}

t_waste	*ww_get_waste(void)
{
	return (*wizard_init());
}
