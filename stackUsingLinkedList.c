#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int n;
	struct node *nextPtr;
} node;
struct node *head = NULL;
void push();
void pop();
void printStack();
int main(void) {
	int ch = 0;
	while(ch != 3) {
		printf("1. Push into the stack.\n 2. Pop from the stack.\n 3. Print stack\n 4. Exit.\n");
		printf("Enter choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: printStack();
					break;
			case 4: return 0;
		}
	}
}

void push() {
	int data;
	printf("Enter elements to push into the stack: ");
	scanf("%d", &data);
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node *));
	ptr->n = data;
	ptr->nextPtr = head;
	head = ptr;
}

void pop() {
	struct node *ptr;
	if(head == NULL) {
		printf("stack overflow!\n");
	} else {
		ptr = head;
		head = head->nextPtr;
		free(ptr);
	}
}

void printStack() {
	struct node* ptr;
	ptr = head;
	while(ptr != NULL) {
		printf("%d ", ptr->n);
		ptr = ptr->nextPtr;
	}
	printf("\n");
}