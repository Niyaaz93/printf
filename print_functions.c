#include "holberton.h"

/**
 * _write_char -  prints a character to the stdout
 * @c: character to be printed
 *
 * Return: 1 (successful), -1 (error)
 */
int _write_char(char c)
{
	return(write(1, &c, 1));
}
/**
 * print_percent - print the percent sign
 * @list: list of arguments
 *
 * Return: returns the amount of characters printed
 */
int print_percent(__attribute__((unused))va_list list)
{
	_write_char('%');
	return (1);
}

/**
 * print_c - prints char
 * @list: arguement char
 * Return: pointer args
 */

char *print_c(va_list list)
{
	static char s[2] = {0, '\0'};

	s[0] = va_arg(list, int);
	if (s[0] == '\0')
		return (" ");
	return (s);
}

/**
 * print_s - prints string
 * @list: list to print
 * Return: pointer args
 */

char *print_s(va_list list)
{
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		return (str = "(null)");
	return (str);
}

/**
 * print_i - Prints an integer
 * @list: list of arguments
 * Return: pointer args
 */

char *print_i(va_list list)
{
	int digit = 0;
	int i = 0;
	int neg = 0;
	int divisor = 1000000000;
	char *output;
	int num = va_arg(list, int);
	int len = _numlen(num);

	output = malloc(len * sizeof(char) + 1 + neg);

	if (output == NULL)
	{
		free(output);
		return (0);
	}

	if (num < 0)
	{
		neg++;
	}

	if (num < 0)
	{
		output[i] = '-';
		i++;
	}

	if (num > -10 && num < 10)
	{
		output[i] = _abs(num) + '0';
		return (output);
	}

	while (divisor)
	{
		digit = (num / divisor) % 10;
		if (num < 0)
		{
			digit = _abs(digit);
		}
		if (digit != 0 || (len >= 0  && output[i - 1] >= '0'))
		{
			output[i] = digit + '0';
			i++;
			len--;
		}
		divisor /= 10;
	}
	output[i] = '\0';
	return (output);
}
