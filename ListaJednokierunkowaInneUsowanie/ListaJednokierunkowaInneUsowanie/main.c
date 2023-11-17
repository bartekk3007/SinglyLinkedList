#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

void addNode(struct ListNode **head, int n)
{
	struct ListNode *vertex = (struct ListNode*) malloc(sizeof(struct ListNode));
	if (*head == NULL)
	{
		*head = vertex;
		if (*head)
		{
			(*head)->val = n;
			(*head)->next = NULL;
		}
	}
	else
	{
		addNode(&(*head)->next, n);
	}
}

void deleteFromRoot(struct ListNode **head, int n)
{
	if ((*head)->next->next == NULL)
	{
		(*head)->val = (*head)->next->val;
		free((*head)->next);
		(*head)->next = NULL;
	}
	else
	{
		(*head)->val = (*head)->next->val;
		deleteFromRoot(&(*head)->next, n);
	}
}

void deleteNode(struct ListNode **head, int n)
{
	if (*head == NULL)
	{
		return;
	}
	else if ((*head)->next == NULL && (*head)->val == n)
	{
		free(*head);
		*head = NULL;
	}
	else if ((*head)->next == NULL)
	{
		return;
	}
	else if ((*head)->val == n)
	{
		deleteFromRoot(head, n);
	}
	else if ((*head)->next->val == n)
	{
		if ((*head)->next->next == NULL)
		{
			free((*head)->next);
			(*head)->next = NULL;
		}
		else
		{
			struct node* temp = (*head)->next->next;
			free((*head)->next);
			(*head)->next = temp;
		}
	}
	else
	{
		deleteNode(&(*head)->next, n);
	}
}

void traverseList(struct ListNode* head)
{
	printf("Lista: ");
	while (head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

void freeList(struct ListNode* head)
{
	struct ListNode* tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main(void)
{
	struct ListNode *head = NULL;
	addNode(&head, 5);
	//addNode(&head, 8);
	//addNode(&head, 13);
	//addNode(&head, 21);
	//addNode(&head, 34);
	//addNode(&head, 55);

	traverseList(head);

	deleteNode(&head, 5);

	traverseList(head);

	addNode(&head, 10);

	traverseList(head);

	freeList(head);

	return 0;
}