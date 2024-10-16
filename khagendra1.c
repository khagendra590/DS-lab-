#include<stdio.h>
#define SIZE 5

void insert(int *front, int *rear, int q[], int x){
    if(*rear==SIZE-1){
        printf("Overflow condition...\n");
    }
    else{
        q[++(*rear)]=x;
    }
}

int del(int *front, int *rear, int q[]){
    if(*front>*rear){
        printf("Underflow condition....\n");
        return -1;
    }
    else{
        return ((q[(*front)++]));
    }
}

void display(int *front, int *rear, int q[]){
    if(*rear == -1){
        printf("Empty stack...");
    }
    else{
        printf("stack elements: ");
        for(int i = *front; i<=*rear; i++){
            printf("%d ",q[i]);
        }
    }
}

void main(){
    int q[SIZE];
    int front = 0;
    int rear = -1;

    int choise;
    int x;

    while(1){
        printf("\n1.Insert element\n2.Delete element\n3.Display \n");
        scanf("%d",&choise);
        switch(choise){
            case 1:
               printf("Enter the element to be performed: ");
               scanf("%d",&x);
               insert(&front,&rear,q,x);
               break;
            case 2:
                if(del(&front,&rear,q)==-1)
                {

                }
                else
                printf("%d  deleted from stack.\n",x);
                break;
            case 3:
                display(&front, &rear, q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
                break;
        }
    }
}

