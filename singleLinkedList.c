#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int n;
	struct node *nextPtr;
} node;	
struct node *head;
void insertAtStart();
void insertAtEnd();
void insertAtPositionBeforeGivenOne();
void printList();
int main(void) {
	int ch = 0;
	while(ch != 4) {
		printf("Choose an option: \n");
		printf("1. Insert at the starting.\n 2. Insert at the ending.\n 3. Insert at a position before given one.\n 4. Print the list.\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insertAtStart();
					break;
			case 2: insertAtEnd();
					break;
			case 3: insertAtPositionBeforeGivenOne();
					break;
			case 4: printList();
					break;
			default:printf("Enter a valid choice:\n");
		}
	}
}

void insertAtStart() {
	struct node *p;
	int num;
	p = (struct node *) malloc (sizeof(struct node*));
	printf("Enter a value to insert into the list: ");
	scanf("%d", &num);
	p->n = num;
	p->nextPtr = head;
	head = p;
}

void insertAtEnd() {
	struct node *p, *temp;
	int num;
	p = (struct node *) malloc(sizeof(struct node *));
	printf("Enter a value to insert into the list: ");
	scanf("%d", &num);
	p->n = num;
	if(head == NULL) {
		p->nextPtr = NULL;
		head = p;
	} else {
		temp = head;
		while(temp->nextPtr != NULL) {
			temp = temp->nextPtr;
		}
		temp->nextPtr = p;
		p->nextPtr = NULL;
	}
}

void insertAtPositionBeforeGivenOne() {
	struct node *p, *temp;
	int pos;
	scanf("%d", &pos);
	int num;
	scanf("%d", &num);
	temp = head;
	p = (struct node *) malloc(sizeof(struct node *));
	p->n = num;
	for(int i = 2; i < pos; i++) {
		if(temp->nextPtr != NULL) {
			temp = temp->nextPtr;
		}
	}
	p->nextPtr = temp->nextPtr;
	temp->nextPtr = p;
}
void printList() {
	struct node *p;
	p = head;
	if(p == NULL) {
		printf("List is empty\n");
	} else {
		while(p != NULL) {
			printf("%d ", p->n);
			p = p->nextPtr;
		}
	}
	printf("\n");
}