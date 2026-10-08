#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s) {
	char	*str = malloc(strlen(s) + 1);
    int parc = 0;
	int i = 0;
	int j = 0;
	while (s[i])
	{
		if (s[i] == '(')
		{
			if (parc != 0)
			{
				str[j] = s[i];
				j++;	
			}
			parc++;
		}
		if (s[i] == ')')
		{
			parc--;
			if (parc != 0)
			{
				str[j] = s[i];
				j++;
			}
		}
		i++;
	}
	str[j] = 0;
	int str_len = strlen(str) + 1;
	str = realloc(str, str_len);
	return (str);
}