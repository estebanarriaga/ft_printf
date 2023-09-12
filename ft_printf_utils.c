
#include "ft_printf.h"
#include <stdarg.h>
#include "./Libft/libft.h"


int ft_print_char(va_list ap)
{
	char c;
	int size;

	size = 0;
	c = va_arg(ap, int);
	size = write(1, &c, 1);
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

int ft_print_unsigned(va_list ap)
{
	unsigned number;
	int size;

	size = 0;
	number = va_arg(ap, unsigned);
	ft_putnbr(number);
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
int ft_print_hex(va_list ap, char c)
{
	int index;
	int number;
	char *buffer;
	int digit;
	char *temp;

	number = va_arg(ap, int);
	digit = number;
	index = 0;
	while (digit > 0)
	{
		digit /= 16;
		index ++;
	}
	buffer = (char *)malloc(index + 1);
	index = 0;
	if (number < 0)
		return (0);
	if (number == 0) {
		// Do some logic for negative hex
		index = write(1, "0", 1);
		return (index);
	}
	while (number > 0)
	{
		digit = number % 16;
		if (digit < 10)
			buffer[index++] = '0' + digit;
		else
			buffer[index++] = c + digit - 10;
		number /= 16;
	}

	temp = ft_reverse_str(buffer, 0, index - 1);
	temp[index] = 0;

	index = write(1, temp, ft_strlen(temp));

	return (index);
}

// int ft_print_decimal_cp(int num, char* str, int* len) {
//     int i = 0;
//     if (num == 0) {
//         str[i++] = '0';
//     } else {
//         while (num > 0) {
//             str[i++] = num % 10 + '0';
//             num /= 10;
//         }
//     }
//     // Reverse the string
//     for (int j = 0; j < i / 2; j++) {
//         char temp = str[j];
//         str[j] = str[i - j - 1];
//         str[i - j - 1] = temp;
//     }
//     *len = i;
// }

// void printFloat(float num) {
//     // Determine the sign of the number
//     int sign = 1;
//     if (num < 0) {
//         sign = -1;
//         num = -num;
//     }

//     // Extract the integer and fractional parts
//     int integerPart = (int)num;
//     float fractionalPart = num - integerPart;

//     // Convert the integer part to a string
//     char intStr[20];
//     int intStrLen = 0;
//     intToStr(integerPart, intStr, &intStrLen);

//     // Convert the fractional part to a string with 6 decimal places
//     char fracStr[20];
//     int fracStrLen = 0;
//     fractionalPart *= 1000000; // 6 decimal places
//     intToStr((int)fractionalPart, fracStr, &fracStrLen);

//     // Write the integer part
//     write(STDOUT_FILENO, intStr, intStrLen);

//     // Write the decimal point
//     char decimalPoint = '.';
//     write(STDOUT_FILENO, &decimalPoint, 1);

//     // Write the fractional part
//     write(STDOUT_FILENO, fracStr, fracStrLen);
// }

int ft_print_decimal(va_list ap)
{
	int index;
	int int_num;
	float decimal_num;
	float fractional_part;

	index = 0;
	decimal_num = va_arg(ap, double);
	int_num = (int)decimal_num;
	index = ft_putnbr(int_num);
	index ++;
	write(1, ".", 1);

	fractional_part = decimal_num - int_num;
	fractional_part *= 1000000;
	index += ft_putnbr((int)fractional_part);

	return (index);
}