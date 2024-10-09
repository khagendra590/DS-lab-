#include <stdio.h>
#define SIZE 5

void push(int array[SIZE], int *top, int x) {
    if (*top == SIZE - 1) {
        printf("overflow condition\n");
    } else {
        (*top)++;
         array[*top] = x;
    }
}

int pop(int array[SIZE], int *top) {
    if (*top == -1) {
        printf("Underflow condition\n");
        return 0;
    } else {
        int res = array[*top];
        (*top)--;
        return res;
    }
}

void display(int array[SIZE], int top) {
    if (top == -1) {
        printf("no stack\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", array[i]);
        }
    }
}

int main() {
    int a[SIZE];
    int choise;
    int top=-1;
    int flag=1;
    int x;
    while (flag) {
        printf("Enter number to be performed:\n 1:push to stack\n 2:pop from stack \n 3:display stack\n");
        scanf("%d", &choise);

        switch (choise) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &x);
                push(a, &top, x);
                break;
            case 2:
                printf("Last item popped: %d\n", pop(a, &top));
                break;
            case 3:
                display(a, top);
                break;
            default:
                printf("Error occurred\n");
                break;
        }

        printf("\nenter 1 to continue or 0 to exit? : ");
        scanf("%d", &flag);
    }

    return 0;
}

