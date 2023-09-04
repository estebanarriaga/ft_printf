
#include "libftprintf.h"
#include <stdarg.h>
#include "Libft/libft.h"


int ft_print_char(va_list ap)
{
	char *c;
	int size;

	size = 0;
	c = va_arg(ap, char *);
	size = write(1, c, 1);
	return (size);
}

int ft_print_str(va_list ap)
{
	char *c;
	int size;

	size = 0;
	c = va_arg(ap, char *);
	size = write(1, c, ft_strlen(c));
	return (size);
}

// Works fine but ft_putnbt needs to return legnth of 'number'
int ft_print_int(va_list ap)
{
	int number;
	int size;

	size = 0;
	number = va_arg(ap, int);
	ft_putnbr_fd(number, 1);
	return (size);
}

static char *ft_reverse_str(char *str, int start, int end)
{
	char temp;

	while (start < end - 1)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end --;
		start ++;
	}
	return (str);
}

int ft_print_ptr_hex(va_list ap) {
    uintptr_t addr = va_arg(ap, uintptr_t);
    char buffer[20];
    int index = 0;

    // Add the '0x' prefix
    buffer[index++] = '0';
    buffer[index++] = 'x';

    // Convert the address to hexadecimal and store it in the buffer
		if (addr == 0)
		{
        int digit = addr % 16;
        buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        addr /= 16;
		}
    while (addr > 0) {
        int digit = addr % 16;
        buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        addr /= 16;
    }

    // Reverse the string in the buffer
    int i, j;
    char temp;
    for (i = 2, j = index - 1; i < j; i++, j--) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    // Null-terminate the string
    buffer[index] = '\0';

    // Use the write function to print the hexadecimal string
    write(1, buffer, index);

		return (index);
}

int ft_print_ptr_hex_upper(va_list ap)
{
    uintptr_t addr = va_arg(ap, uintptr_t);
    char buffer[20];
    int index = 0;

    // Add the '0x' prefix
    buffer[index++] = '0';
    buffer[index++] = 'x';

    // Convert the address to hexadecimal and store it in the buffer
		if (addr == 0)
		{
        int digit = addr % 16;
        buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        addr /= 16;
		}
    while (addr > 0) {
        int digit = addr % 16;
        buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        addr /= 16;
    }

    // Reverse the string in the buffer
    int i, j;
    char temp;
    for (i = 2, j = index - 1; i < j; i++, j--) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    // Null-terminate the string
    buffer[index] = '\0';

    // Use the write function to print the hexadecimal string
    write(1, buffer, index);

		return (index);
}
// Missing check if int is unsigned.
int ft_print_hex(va_list ap)
{
	int index;
	int number;
	char buffer[20];
	int digit;
	char *temp;

	number = va_arg(ap, int);
	if (number < 0)
		return (0);
	index = 0;
	while (number > 0)
	{
		digit = number % 16;
		if (digit < 10)
			buffer[index++] = '0' + digit;
		else
			buffer[index++] = 'a' + digit - 10;
		number /= 16;
	}

	temp = ft_reverse_str(buffer, 0, index - 1);
	temp[index] = 0;

	index = write(1, temp, ft_strlen(temp));

	return (index);
}
