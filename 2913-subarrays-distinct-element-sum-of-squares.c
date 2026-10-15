int countDistinct(int* nums, int start, int end)
{
	int count = 0;
	for (int i = start; i <= end; i++)
	{
		bool dupe = false;
		for (int j = start; j < i; j++)
		{
			if (nums[i] == nums[j])
			{
				dupe = true;
				break;
			}
		}
		if (!dupe)
			count++;
	}
	return (count);
}

int sumCounts(int* nums, int numsSize) {
	int sum = 0;
	int	count;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i; j < numsSize; j++)
		{
			count = countDistinct(nums, i, j);
			sum += count * count;
		}
	}
	return (sum);
}

#include <stdio.h>
int main(void)
{
	int	nums[] = {1, 2, 1};
	printf("%d", sumCounts(nums, 3));
}