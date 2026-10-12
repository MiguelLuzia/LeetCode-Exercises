int maxSum(int* nums, int numsSize, int k) {
    const long long	MAXMOD = 1000000007;
	int c[30] = {0};
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (nums[i] & (1 << j))
				c[j]++;
		}
	}

	long long	result = 0;
	for (int i = 0; i < k; i++)
	{
		long long	cur = 0;
		for (int j = 29; j >= 0; j--)
		{
			if (c[j] > 0)
			{
				cur |= (1LL << j);
				c[j]--;
			}
		}
		result = (result + cur * cur) % MAXMOD;
	}
	return ((int)result);
}

#include <stdio.h>
int main(void)
{
	int nums[] = {2, 6, 5, 8};
	printf("%d", maxSum(nums, 4, 2));
}