struct ListNode {
	int val;
    struct ListNode *next;
};

#include <stdlib.h>

int arrlen(struct ListNode* list1, struct ListNode* list2)
{
	int len = 0;
	struct ListNode* l1 = list1;
	struct ListNode* l2 = list2;
	while (l1 != NULL)
	{
		l1 = l1->next;
		len++;
	}
	while (l2 != NULL)
	{
		l2 = l2->next;
		len++;
	}
	return (len);
}

int *createArr(struct ListNode* list1, struct ListNode* list2, int len)
{
	// Create Array
	struct ListNode* l1 = list1;
	struct ListNode* l2 = list2;
	int	*arr = (int *)malloc(sizeof(int) * (len + 1));
	if (!arr)
		return arr;
	int i = 0;
	while (l1 != NULL)
	{
		arr[i] = l1->val;
		l1 = l1->next;
		i++;
	}
	while (l2 != NULL)
	{
		arr[i] = l2->val;
		l2 = l2->next;
		i++;
	}
	return (arr);
}

void sortArr(int *arr, int len)
{
	int i = 0;
	int j;
	int temp;
	while (i < len)
	{
		j = 0;
		while (j + 1 < len)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

struct ListNode* createElem(int data)
{
    struct ListNode *elem = NULL;
    elem = malloc(sizeof(struct ListNode));
    elem->val = data;
    elem->next = NULL;
    return elem;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	int len = arrlen(list1, list2);
	int	*arr = createArr(list1, list2, len);
	if (!arr)
		return (NULL);
	sortArr(arr, len);

	// Create final list
	struct ListNode	*head = NULL;
	struct ListNode	*tail = NULL;
	struct ListNode *new_node = NULL;
	int i = 0;
	while (i < len)
	{
		new_node = createElem(arr[i]);
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		i++;
	}
	return (head);
}


#include <stdio.h>
int main(void)
{
    struct ListNode *elem1 = createElem(1);
    struct ListNode *elem2 = createElem(2);
    struct ListNode *elem3 = createElem(4);
	elem1->next = elem2;
	elem2->next = elem3;

    printf("%d\n", elem1->val);
    printf("%d\n", elem1->next->val);
    printf("%d\n", elem1->next->next->val);

    struct ListNode *elem5 = createElem(1);
    struct ListNode *elem6 = createElem(3);
    struct ListNode *elem7 = createElem(4);
	elem5->next = elem6;
	elem6->next = elem7;

    printf("%d\n", elem5->val);
    printf("%d\n", elem5->next->val);
    printf("%d\n", elem5->next->next->val);
    
	printf("\n");
	struct ListNode *list = mergeTwoLists(elem1, elem5);
	while (list != NULL)
	{
    	printf("%d\n", list->val);
		list = list->next;
	}
}