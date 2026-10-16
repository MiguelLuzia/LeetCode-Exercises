#include <string.h>

#define MAX 100005
#define MOD 1000000007LL

long long treeSum[4 * MAX];
long long treeSquares[4 * MAX];
int lazyAdd[4 * MAX];

void apply(int node, int left, int right, int delta)
{
    long long length = right - left + 1;
    treeSquares[node] =
        (treeSquares[node]
        + 2LL * delta * treeSum[node]
        + (long long)delta * delta * length) % MOD;
    treeSum[node] =
        (treeSum[node] + (long long)delta * length) % MOD;
    lazyAdd[node] += delta;
}

void push(int node, int left, int right)
{
    if (lazyAdd[node] == 0 || left == right)
        return;
    int middle = (left + right) / 2;
    apply(node * 2, left, middle, lazyAdd[node]);
    apply(node * 2 + 1, middle + 1, right, lazyAdd[node]);
    lazyAdd[node] = 0;
}

void update(int node, int left, int right,
            int queryLeft, int queryRight)
{
    if (queryLeft <= left && right <= queryRight)
    {
        apply(node, left, right, 1);
        return;
    }
    push(node, left, right);
    int middle = (left + right) / 2;
    if (queryLeft <= middle)
        update(node * 2, left, middle,
               queryLeft, queryRight);
    if (queryRight > middle)
        update(node * 2 + 1, middle + 1, right,
               queryLeft, queryRight);
    treeSum[node] =
        (treeSum[node * 2] + treeSum[node * 2 + 1]) % MOD;

    treeSquares[node] =
        (treeSquares[node * 2] + treeSquares[node * 2 + 1]) % MOD;
}

int sumCounts(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    memset(treeSum, 0, sizeof(treeSum));
    memset(treeSquares, 0, sizeof(treeSquares));
    memset(lazyAdd, 0, sizeof(lazyAdd));
    int lastIndex[100001];
    for (int i = 0; i <= 100000; i++)
        lastIndex[i] = -1;
    long long answer = 0;
    for (int i = 0; i < numsSize; i++)
    {
        update(1, 0, numsSize - 1,
               lastIndex[nums[i]] + 1, i);
        lastIndex[nums[i]] = i;
        answer = (answer + treeSquares[1]) % MOD;
    }
    return (int)answer;
}

#include <stdio.h>
int main(void)
{
	int	nums[] = {1, 2, 1};
	printf("%d", sumCounts(nums, 3));
}