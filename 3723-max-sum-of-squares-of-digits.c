#include <stdlib.h>
char* maxSumOfSquares(int num, int sum) {
	if (sum > 9 * num)
	{
        char* n = malloc(1);
        n[0] = '\0';
        return n;
    }
	char *n = malloc(num + 1);
	int i = 0;
	int r = sum % 9;
	int nn = sum / 9;
	while (i < nn)
		n[i++] = '9';
	if (r > 0)
		n[i++] = '0' + r;
	while (i < num)
		n[i++] = '0';
	n[i] = 0;
	return n;
}


#include <stdio.h>
int main(void)
{
	printf("%s", maxSumOfSquares(2, 3));
}