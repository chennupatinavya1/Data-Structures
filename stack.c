/*#include <stdio.h>
#include <stdlib.h>
int top = -1;
void push(int arr[], int n, int top, int value);
int pop(int arr[], int top);
int peek(int arr[], int n, int top);
int main(void) {
	int n, value;
	printf("Enter size of stack: ");
	scanf("%d", &n);
	int stack[n];
	int choice, res, res1;
	printf("Enter choice: ");
	scanf("%d", &choice);
	while(1) {
		switch(choice) {
			case 1:printf("Enter value: ");
					scanf("%d", &value);
					push(stack, n, top, value);
					break;
			case 2:res = pop(stack, top);
					if(res == -1) {
						printf("Underflow\n");
						break;
					}
					else {
						printf("%d\n", res);
					}
					break;
			case 3:res1 = peek(stack, n, top);
					if(res1 == -1) {
						printf("Underflow\n");
					}
					else {
						printf("%d\n", res1);
					}
					break;
			case 4: exit(0);
					break;
		}
	}
}
void push(int stack[], int n, int top, int value) {
	if(top == n - 1) {
		printf("Overflow\n");

	}
	else {
		stack[top] = value;
		top++;
	}
}

int pop(int stack[], int top) {
	if(top == -1) {
		return -1;
	}
	else {
		int value1;
		value1 = stack[top];
		top--;
		return value1;
	}
}

int peek(int stack[], int n, int top) {
	if(top == -1) {
		return -1;
	}
	else {
		return stack[top];
	}
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
void push(int *stack, int n, int *top);
void pop(int *stack, int *top);
void peek(int *stack, int *top);
int main(void) {
	int n, *stack, ch;
	printf("Enter size: ");
	scanf("%d", &n);
	stack = (int *) malloc(sizeof(int) * n);
	int top = -1;
	do {
		printf("Enter choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:push(stack, n, &top);
					break;
			case 2:pop(stack, &top);
					break;
			case 3:peek(stack, &top);
					break;
			case 4:exit(0);
					break;
		}
	} while(ch < 5);
}

void push(int stack[], int n, int *top) {
	int ele;
	if(*top == n - 1) {
		printf("Overflow!\n");
	}
	else{
		printf("Enter element: ");
		scanf("%d", &ele);
		*top++;
		stack[*top] = ele;
	}
}

void pop(int stack[], int *top) {
	int ele;
	if(*top == -1) {
		printf("Underflow!\n");
	}
	else {
		ele = stack[*top];
		*top--;
		printf("deleted element: %d\n", ele);
	}
}

void peek(int stack[], int *top) {
	if(*top == -1) {
		printf("Underflow!\n");
	}
	else {
		for(int i = *top; i >= 0; i--) {
			printf("%d\n", stack[i]);	
		}
		
	}
}*/

#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
	int arr[10];
	int top;
} stack;
int count = 0;
void push(stack *st, int ele) {
	if(st->top == 10) {
		printf("Stack Overflow!\n");
	} else {
		st -> top++;
		st->arr[st->top] = ele;
	}
	count++;
}

void pop(stack *st) {
	if(st->top == -1) {
  		printf("Stack Underflow!\n");
  	} else {
    	printf("Deleted element = %d\n", st->arr[st->top]);
    	st->top--;
  	}
  	count--;
}

void display(stack *st) {
	for(int i = 0; i < count; i++) {
		printf("%d ", st->arr[i]);
	}
	printf("\n");
}

int main(void) {
	stack *st = (stack *)malloc(10 * sizeof(st));
	st->top = -1;
	int ele, ch;
  	int n;
  	scanf("%d", &n);
  	for(int i = 0; i < n; i++) {
  		printf("1. Push\n 2. Pop \n 3. Display\n");
		scanf("%d", &ch);
 		switch(ch) {
  			case 1:scanf("%d", &ele);
  					push(st, ele);
  					break;
  			case 2: pop(st);
  					break;
  			case 3: printf("elements of the stack: ");
  					display(st);
  					break;
  			case 4: exit(0);
  		}
  	}
}