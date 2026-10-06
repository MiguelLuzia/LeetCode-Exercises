int checkValidString(char *s)
{
	int c = 0;

	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(')
			c++;
		else if (s[i] == ')')
			c--;
		if (c < 0)
			return (0);
	}
	return (c == 0);
}

int minAddToMakeValid(char* s) {
    if (checkValidString(s))
		return (0);
	int c = 0;
	int toOpen = 0;
	int i = 0;
	while (s[i])
	{
		if (c <= 0 && s[i] == ')')
			toOpen++;
		else if (c > 0 && s[i] == ')')
			c--;
		else if (s[i] == '(')
			c++;
		i++;
	}
	return (c + toOpen);
}

#include <stdio.h>
int main(void)
{
	printf("%d", minAddToMakeValid("))("));
}