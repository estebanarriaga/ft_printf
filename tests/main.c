
#include "../libftprintf.h"
#include <assert.h>
#include <sys/time.h>

int	main(void)
{
	char c = 'A';
	char *str = "This happens when your program reads or writes memory at a place which Memcheck reckons it shouldn't. In this example, the program did a 4-byte read at address 0xBFFFF0E0, somewhere within the system-supplied library libpng.so.2.1.0.9, which was called from somewhere else in the same library, called from line 326 of qpngio.cpp, and so on.Memcheck tries to establish what the illegal address might relate to, since that's often useful. So, if it points into a block of memory which has already been freed, you'll be informed of this, and also where the block was freed. Likewise, if it should turn out to be just off the end of a heap block, a common result of off-by-one-errors in array subscripting, you'll be informed of this fact, and also where the block was allocated. If you use the --read-var-info option Memcheck will run more slowly but may give a more detailed description of any illegal address.";
	int num = 42;
	// ASSERTION TESTING
	assert(ft_printf("Character: %c\n", 'A') == printf("Character: A\n"));
	assert(ft_printf("String: %s\n", str) == printf("String: %s\n", str));
	assert(ft_printf("Integer: %i\n", num) == printf("Integer: %i\n", num));
	assert(ft_printf("Escaping %%: %%\n") == printf("Escaping %%: %%\n"));
	printf("All test cases passed!\n");

	// MEMORY TESTING.
	 

	// PERFORMANCE TESTING:
/* 	struct timeval t0, t1;
	unsigned int i;

	gettimeofday(&t0, NULL);
	for(i = 0; i < 100000; i++)
		function_to_measure();
	gettimeofday(&t1, NULL);
	printf("Did %u calls in %.2g seconds\n", i, t1.tv_sec - t0.tv_sec + 1E-6 * (t1.tv_usec - t0.tv_usec));
 */
	return (0);	
}