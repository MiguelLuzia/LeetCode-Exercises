#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
	int	*indexes = (int *)malloc(2 * sizeof(int));
	int i = 0;
	int j;
	while (i < numsSize)
	{
		j = 0;
		while (j < numsSize)
		{
			if (i == j)
			{
				j++;
				continue;
			}
			if (nums[i] + nums[j] == target)
			{
				indexes[0] = i;
				indexes[1] = j;
				return (indexes);
			}
			j++;
		}
		i++;
	}
	return (indexes);
}

#include <stdio.h>
int main(void)
{
	int nums[] = {3,2,4};
	int rsize = 2;
	int *arr = twoSum(nums, 3, 6, &rsize);
	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
}