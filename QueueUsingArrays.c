#include <stdio.h>
#define n 10
int rear = -1, front = -1, arr[10];
void enqueue();
void dequeue();
void printQueue();
int main(void) {
	int ch = 0;
	while(ch != 4) {
		printf("1. Enqueue\n 2. Dequeue\n 3. Print Queue\n 4.Exit\n");
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
	int num;
	printf("Enter element to be inserted into the queue: ");
	scanf("%d", &num);
	if(rear == n - 1) {
		printf("Queue Full\n");
	} else {
		if(front == -1) {
			front = 0;
		}
		rear++;
		arr[rear] = num;
	}
}

void dequeue() {
	if(front == -1) {
		printf("Empty queue\n");
	} else {
		front++;
		if(front > rear) front = rear = -1;
	}
}

void printQueue() {
	for(int i = front; i <= rear; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}