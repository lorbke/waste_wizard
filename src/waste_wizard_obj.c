
#include "waste_wizard.h" // t_waste
#include <stdlib.h> // NULL

/**
 * It returns a pointer to a static variable,
 * representing the main waste list.
 * 
 * @return A pointer to a pointer to a t_waste struct.
 */
t_waste	**wizard_init(void)
{
	static t_waste	*waste = NULL;

	return (&waste);
}

/**
 * It returns a pointer to the main waste list.
 * 
 * @return A pointer to a pointer to a 
 * function that returns a pointer to a struct.
 */
t_waste	*ww_get_waste(void)
{
	return (*wizard_init());
}
