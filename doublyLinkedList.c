#include <stdio.h>
#include <stdlib.h>
typedef struct doublyLinkedList {
	int n;
	struct doublyLinkedList *nextPtr;
	struct doublyLinkedList *prevPtr;
} doublyLinkedList;

struct doublyLinkedList *head;
void insertAtTheBeginning();
void printList();
int main(void) {
	int ch = 0;
	while(ch != 4) {
		printf("Choose an option: ");
		printf("1. Insert an element at the start.\n 2. Insert an element at the end.\n 3.Print the list.\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insertAtTheBeginning();
					break;
			case 2: insertAtTheEnd();
					break;
			case 3: printList();
					break;
		}
	}
}

void insertAtTheBeginning() {
	struct doublyLinkedList *ptr;
	ptr = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
	int num;
	printf("Enter the value to insert into the list: ");
	scanf("%d", &num);
	ptr->n = num;
	if(head == NULL) {
		ptr->nextPtr = NULL;
		ptr->prevPtr = NULL;
		head = ptr;
	} else {
		ptr->prevPtr = NULL;
		ptr->nextPtr = head;
		head->prevPtr = ptr;
		head = ptr;
	}
}
void insertAtTheEnd() {
	struct doublyLinkedList *ptr, *temp;
	ptr = (struct doublyLinkedList *) malloc(sizeof(struct doublyLinkedList));
	int num;
	printf("Enter an element to insert into the list: ");
	scanf("%d", &num);
	ptr->n = num;
	if(head == NULL) {
		ptr->nextPtr = NULL;
		ptr->prevPtr = NULL;
		head = ptr;
	} else {
		temp = head;
		while(temp->nextPtr != NULL) {
			temp = temp->nextPtr;
		}
		temp->nextPtr = ptr;
		ptr->prevPtr = temp;
		ptr->nextPtr = NULL;
	}
	
}
void printList() {
	struct doublyLinkedList *temp;
	temp = head;
	if(temp == NULL) {
		printf("No values to print!\n");
	} else {
		while(temp != NULL) {
			printf("%d ", temp->n);
			temp = temp->nextPtr;
		}
	}
}