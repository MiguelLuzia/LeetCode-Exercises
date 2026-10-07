#include <stdlib.h>
#include <string.h>

int checkValidString(char *s)
{
	int c = 0;
	int i = 0;

	while (s[i])
	{
		if (s[i] == '(')
			c++;
		else if (s[i] == ')')
			c--;
		if (c < 0)
			return (0);
		i++;
	}
	return (c == 0);
}

int alreadyExists(char **result, int returnSize, char *current)
{
	int i;

	i = 0;
	while (i < returnSize)
	{
		if (strcmp(result[i], current) == 0)
			return (1);
		i++;
	}
	return (0);
}

void solve(char *s, int index, int toOpen, int toClose, char *current, int currentSize, char ***result, int *returnSize, int *capacity)
{
	if (index == strlen(s))
	{
		current[currentSize] = '\0';

		if (toOpen == 0 && toClose == 0 && checkValidString(current))
		{
			if (!alreadyExists(*result, *returnSize, current))
			{
				if (*returnSize >= *capacity)
				{
					*capacity *= 2;
					*result = realloc(*result,
						sizeof(char *) * (*capacity));
				}
				(*result)[*returnSize] = malloc(strlen(current) + 1);
				strcpy((*result)[*returnSize], current);
				(*returnSize)++;
			}
		}
		return;
	}
// keep
    current[currentSize] = s[index];
    solve(s, index + 1, toOpen, toClose,
          current, currentSize + 1,
          result, returnSize, capacity);
// remove
    if (s[index] == '(' && toClose > 0)
    {
        solve(s, index + 1, toOpen, toClose - 1,
              current, currentSize,
              result, returnSize, capacity);
    }
    else if (s[index] == ')' && toOpen > 0)
    {
        solve(s, index + 1, toOpen - 1, toClose,
              current, currentSize,
              result, returnSize, capacity);
    }
}

char** removeInvalidParentheses(char* s, int* returnSize) {
	char **result;
	int i = 0;

	if (checkValidString(s))
	{
		result = malloc(sizeof(char *));
		result[0] = malloc(strlen(s) + 1);
		while (s[i])
		{
			result[0][i] = s[i];
			i++;
		}
		result[0][i] = 0;
		*returnSize = 1;
		return (result);
	}

	int toClose = 0;
	int toOpen = 0;
	while (s[i])
	{
		if (toClose <= 0 && s[i] == ')')
			toOpen++;
		else if (toClose > 0 && s[i] == ')')
			toClose--;
		else if (s[i] == '(')
			toClose++;
		i++;
	}
	// toClose > 0 == remover aberturas
	// toOpen > 0 == remover finais
	int capacity = 10;

	result = malloc(sizeof(char *) * capacity);
	if (!result)
		return (result);
	char *current = malloc(strlen(s) + 1);
	*returnSize = 0;
	solve(s, 0, toOpen, toClose, current, 0, &result, returnSize, &capacity);
	return (result);
}

#include <stdio.h>
int main(void)
{
	char *s = "(()";
	int size = 3;
	char **arr = removeInvalidParentheses(s, &size);
	printf("%s", arr[0]);
}