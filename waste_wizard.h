
#ifndef WASTE_WIZARD_H
# define WASTE_WIZARD_H

# include <sys/types.h> // size_t

/*********************************/
/*			DESCRIPTION			 */
/*********************************/
/* 
* This set of functions will keep track of memory allocations which can
* be added as pointers. The allocations can then later be freed.
*/

typedef struct s_waste
{
	void	*alloc;
	void	(*func_free)(void *);
	struct s_waste	*next;
}	t_waste;

t_waste		*ww_get_waste(void);
void		ww_add_waste(void *alloc, void (*func_free)(void *));
void		*ww_malloc_and_add(size_t size, size_t count);
void		ww_free_all_waste(void);

// useful free functions
void		ww_free_str_arr(void *str_arr_void);

#endif
