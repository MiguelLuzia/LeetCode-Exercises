int checkValidString(char *s)
{
	int c = 0;

	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(')
			c += 2;
		else if (s[i] == ')')
			c--;
		if (c < 0)
			return (0);
	}
	return (c == 0);
}

int minInsertions(char* s) {
    if (checkValidString(s))
		return (0);
	int c = 0;
	int tco = 0;
	int toOpen = 0;
	int i = 0;
	while (s[i])
	{
		if (c <= 0 && s[i] == ')' && (!s[i + 1] || s[i + 1] != ')'))
			tco++;
		else if (c <= 0 && s[i] == ')' && s[i + 1] && s[i + 1] == ')')
		{
			i++;
			toOpen++;
		}
		else if (c > 0 && s[i + 1] && s[i] == ')' && s[i + 1] == ')')
		{
			i++;
			c--;
		}
		else if (c > 0 && s[i] == ')' && (!s[i + 1] || s[i + 1] != ')'))
		{
			toOpen++;
			c--;
		}
		else if (s[i] == '(')
			c++;
		i++;
	}
	return (c * 2 + toOpen + 2 * tco);
}

#include <stdio.h>
int main(void)
{
	printf("%d", minInsertions("(()))(()))()())))"));
}