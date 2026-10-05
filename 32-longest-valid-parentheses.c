int checkOpenings(char* s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			return (1);
		i++;
	}
	return (0);
}

int checkEndings(char* s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == ')')
			return (1);
		i++;
	}
	return (0);
}

int checkIfValid(char* s, int pos, int parc)
{
	while (s[pos] && parc != 0)
	{
		if (s[pos] == ')')
			parc--;
		if (s[pos] == '(')
			parc++;
		pos++;
	}
	if (parc == 0)
		return (1);
	return (0);
}

int	longestValidParentheses(char* s) {
	if (!checkOpenings(s) || !checkEndings(s))
		return (0);

	int curlen = 0;
	int maxlen = 0;
	int parc = 0;
	int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
		{
			parc++;
			if (checkIfValid(s, i + 1, parc))
				curlen += 2;
			else
			{
				if (curlen > maxlen)
					maxlen = curlen;
				curlen = 0;
				parc = 0;
			}
		}
		if (s[i] == ')')
			parc--;
		if (parc < 0)
		{
			if (curlen > maxlen)
				maxlen = curlen;
			curlen = 0;
			parc = 0;	
		}
		i++;
		if (!s[i] && curlen > maxlen)
			maxlen = curlen;
	}
	return (maxlen);
}

#include <stdio.h>
int main(void)
{
	printf("%d", longestValidParentheses(")()())()()("));
}
