int myAtoi(char* s) {
	long num = 0;
	int signal = 1;
	int i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			signal *= -1;
		i++;
	}
	while (s[i] == '0')
		i++;
	int c = 0;
	while (s[i] && '0' <= s[i] && s[i] <= '9')
	{
		num *= 10;
		num += s[i] - '0';
		i++;
		c++;
		if (c == 11)
		{
			if (signal == -1)
				return (-2147483648);
			else
				return (2147483647);
		}
	}
	num *= signal;
	if (num < -2147483648)
		num = -2147483648;
	if (num > 2147483647)
		num = 2147483647;
	return ((int)num);
}

#include <stdio.h>
int main(void)
{
	printf("%d", myAtoi("-214748364899999999999999999999"));
}