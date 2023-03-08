# Waste Wizard

Waste Wizard is a simple garbage collector that can be used by C programs.


## Explanation

The garbage collector works by providing a wrapper function for malloc, 
which besides allocating memory will also add a pointer to the allocation 
to a static waste list which can then be freed later on in the program.


## Usage

```C
include "waste_wizard.h"

/*
Creates a new area, which essentially is a new separate waste list.
The area_num is assigned to the waste list as an identifier for future use.
*/
ww_add_area(area_num);


/*
Adds an already allocated object to the waste list of the specified area.
The second parameter is a pointer to a function that will be used to free 
the allocation later on. If the second parameter is NULL, free() is used.
*/
ww_add_waste(area_num, allocation, &free_function);


/*
This is a wrapper for malloc, which will allocate memory of the size specified 
in the parameters and also add the allocation to the static waste list of
the specified area.

Beware: Replacing every malloc in your code with this wrapper can lead to
significant performance slumps because the list of pointers that is managed
by the wizard can become very big. It is recommended to allocate big data
structures like structs, lists or arrays with the normal malloc and to use
ww_add_waste to add the head pointer to the wizard.
*/
ww_malloc_and_add(area_num, size, count);


/*
Calling this function will free every allocation in the waste list in the
specified area by using the provided free function.
*/
ww_free_area(area_num);


/*
Calling this function will free every allocation in every area.

Always call this function at the end of your program to prevent leaks!
*/
ww_free_all_areas();
```
