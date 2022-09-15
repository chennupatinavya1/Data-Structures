#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int n;
	struct node *nextPtr;
}node;
struct node *head;
struct node *front = NULL, *rear = NULL;
void enqueue();
void dequeue();
void printQueue();
int main(void) {
	int ch = 0;
	while(ch != 4) {
		printf("1. Insert into the queue\n 2. Delete from the queue.\n 3. Print queue\n 4. Exit loop\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: printQueue();
					break;
			case 4: return 0;
		}
	}
}

void enqueue() {
	struct node *ptr;
	int num;
	ptr = (struct node *) malloc(sizeof(struct node));
	printf("Enter element to be inserted: ");
	scanf("%d", &num);
	ptr->n = num;
	ptr->nextPtr = NULL;
	if(front == NULL && rear == NULL) {
		front = rear = ptr;
	} else {
		rear->nextPtr = ptr;
		rear = ptr;
	}
}

void dequeue() {
	struct node *currentNode;
	if(front == NULL) {
		printf("Empty queue\n");
	} else {
		currentNode = front;
		front = front->nextPtr;
		if(front == NULL) {
			rear = NULL;
		}
		free(currentNode);
	}
}

void printQueue() {
	struct node *temp = front;
	while(temp) {
		printf("%d ", temp->n);
		temp = temp->nextPtr;
	}
	printf("\n");
}