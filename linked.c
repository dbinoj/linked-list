#include <stdio.h>
#include <stdlib.h>

struct node	{
	int data;
	struct node *next;
	struct node *prev;
};

struct list	{
	struct node *head;
	struct node *tail;
};

int listInit(struct list *sList)	{
	sList->head = NULL;
	sList->tail = NULL;
	return 0;
}

int push(struct list *sList, int data)	{
	struct node *p;
	p = malloc(sizeof(struct node));
	p->data = data;
	p->next = sList->head;
	if(sList->tail == NULL)	{
		p->next = NULL;
		sList->tail = p;
	}
	sList->head = p;
	return 0;
}

int insert(struct list *sList, int data)	{
	if(sList->head == NULL)
		push(sList, data);
	else	{
		struct node *p = sList->head;
		struct node *i;
		if(p->data >= data) {
			i = malloc(sizeof(struct node));
			i->data = data;
			i->next = p;
			sList->head = i;
			return 0;
		}
		while (p->next != NULL && p->next->data < data)
			p=p->next;
		i = malloc(sizeof(struct node));
		i->data=data;
		i->next=p->next;
		p->next=i;
		return 0;
	}
}

int pop(struct list *sList)	{
	if(sList->head != NULL)	{
		struct node *p = sList->head;
		sList->head = sList->head->next;
		int temp = p->data;
		free(p);
		return temp;
	}
	return -1;
}

int print(struct list *sList)	{
	struct node *p = sList->head;
	while(p != NULL)	{
		printf("%d ", p->data);
		p = p->next;
	}
	return 0;
}

int printrev(struct list *sList)	{
	struct node *p = sList->tail;
	while(p != NULL)	{
		printf("%d ", p->data);
		p = p->prev;
	}
	return 0;
}

int main()	{
	int dataIN;
	struct list myList;
	printf("Initiating List...\n\r");
	listInit(&myList);
	printf("List initialized!\n\r");
	printf("Enter Values to insert. ('0' to stop)\n\r");
	while(1)	{
		scanf("%d", &dataIN);
		if (dataIN == 0)
			break;
		push(&myList, dataIN);
	}
	/*while(myList.head != NULL)	{
		printf("%d ", pop(&myList));
	} */
	printrev(&myList);
	printf("END");
	return 0;
}
