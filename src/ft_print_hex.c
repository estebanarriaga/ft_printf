
#include "ft_printf.h"
#include "libft.h"

// static char *ft_reverse_str(char *str, int start, int end)
// {
// 	char temp;

// 	while (start < end)
// 	{
// 		temp = str[start];
// 		str[start] = str[end];
// 		str[end] = temp;
// 		end --;
// 		start ++;
// 	}
// 	return (str);
// }


// static char *ft_transform_to_hex(unsigned int addr, char c)
// {
// 	int temp;
// 	int temp_remainder;

// 	if (addr >= 16)
// 		temp = addr % 16;
// 		temp *= 16;
// 		addr = addr / 16;
// }

// int ft_print_ptr_hex_test(va_list ap) {
//     unsigned int addr = va_arg(ap, unsigned int);
// 		if (!addr)
// 			return (0);
//     char buffer[20];
//     int index = 0;

//     buffer[index++] = '0';
//     buffer[index++] = 'x';

// 		if (addr == 0)
// 		{
//         write(1, "0x", 2);
// 				return (2);
// 		}
//     while (addr > 0) {
//         int digit = addr % 16;
//         buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
//         addr /= 16;
//     }

//     // Reverse the string in the buffer
//     int i, j;
//     char temp;
//     for (i = 2, j = index - 1; i < j; i++, j--) {
//         temp = buffer[i];
//         buffer[i] = buffer[j];
//         buffer[j] = temp;
//     }

//     // Null-terminate the string
//     buffer[index] = '\0';

//     // Use the write function to print the hexadecimal string
//     write(1, buffer, index);

// 		return (index);
// }

// int ft_print_ptr_hex(va_list ap)
// {
// 	int length;
// 	unsigned long long ptr;

// 	length = 0;
// 	length = write(1, "0x", 1);
// 	ptr = va_arg(ap, unsigned long long);
// 	if (ptr == 0)
// 		length += write(1, "0", 1);
// 	else
// 	{
// 		ft_put
// 	}
// 	return (length);
// }

// static int ft_get_number_size(unsigned int number)
// {
// 	int	len;

// 	len = 0;
// 	while (number != 0)
// 	{
// 		number = number / 16;
// 		len++;
// 	}
// 	return (len);
// }

// // Missing check if int is unsigned.
// int ft_print_hex(va_list ap, char c)
// {
// 	int index;
// 	unsigned int number;
// 	char *buffer;
// 	int digit;

// 	number = va_arg(ap, unsigned int);
// 	if (c == 'p')
// 		write(1, "0x", 2);
// 	if (number == 0)
// 	{
// 		write(1, "0", 1);
// 		return (1);
// 	}
// 	index = ft_get_number_size(number);
// 	buffer = (char *)malloc(index + 1);
// 	index = 0;
// 	if (!buffer)
// 		return (0);
// 	while (number > 0)
// 	{
// 		digit = number % 16;
// 		if (digit < 10)
// 			buffer[index++] = '0' + digit;
// 		else
// 			buffer[index++] = c + digit - 10;
// 		number /= 16;
// 	}

// 	buffer = ft_reverse_str(buffer, 0, index - 1);
// 	buffer[index] = 0;
// 	index = write(1, buffer, ft_strlen(buffer));

// 	free(buffer);
// 	return (index);
// }

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, c);
		ft_put_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + c));
	}
}

int	ft_print_hex(va_list ap, const char c)
{
	unsigned int number;
	int	length;

	number = va_arg(ap, unsigned int);
	length = ft_hex_len(number);
	if (number == 0)
		length += write(1, "0", 1);
	else
		ft_put_hex(number, c);
	return (length);
}
