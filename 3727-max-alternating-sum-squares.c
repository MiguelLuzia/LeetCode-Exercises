#include <stdlib.h>

int	comp(const void *a, const void *b)
{
	long long x = *(const long long *)a;
	long long y = *(const long long *)b;
    return (x < y) - (x > y);
}

long long	maxAlternatingSum(int* nums, int numsSize) {
	int ns = numsSize;
	if (numsSize % 2 != 0)
		ns++;
	long long n[ns];
	for (int i = 0; i < numsSize; i++)
		n[i] = abs(nums[i]);
	if (numsSize % 2 != 0)
		n[numsSize] = 0;
	
	qsort(n, ns, sizeof(n[0]), comp);
	int j = ns - 1;
	for (int i = 0; i < j; i++)
	{
		n[i] *= n[i];
		n[i] -= n[j] * n[j];
		n[j] = 0;
		j--;
	}
	long long	sum = 0;
	for (int i = 0; i < ns; i++)
		sum += n[i];
	return (sum);
}

#include <stdio.h>
int main(void)
{
	int nums[] = {2, 1, 3}; //{1, 2, 3, 3, 4, 84, 1000}
	int numsSize = 3;
	long long sum = maxAlternatingSum(nums, numsSize);
	printf("%lld", sum);
}