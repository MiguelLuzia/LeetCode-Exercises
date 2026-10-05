int returnPower(int base, int exponent)
{
	int power = base;
	if (exponent == 0)
		return (1);
	while (exponent > 1)
	{
		power *= base;
		exponent--;
	}
	return (power);
}

int scoreOfParentheses(char* s) {
    int i = 0;
	int mult = 0;
	int score = 0;
	int curscore = 0;

	while (s[i])
	{
		if (s[i] == '(')
		{
			if (s[i + 1] && s[i + 1] == ')')
			{
				curscore++;
				curscore *= returnPower(2, mult);
				score += curscore;
				curscore = 0;
				i++;
			}
			else if (s[i + 1] && s[i + 1] == '(')
				mult++;
		}
		else if (s[i] == ')')
			mult--;
		i++;
	}
	return (score);
}

#include <stdio.h>
int main(void)
{
	char *s = "((())())";
	printf("%d", scoreOfParentheses(s));
}