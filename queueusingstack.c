#include<stdio.h>

#define n 5
int stack1[n];
int stack2[n];
int top1= -1;
int top2= 0;

void popstack2(){
   
    top2--;
   
    }
    


void enqueue() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);
    if(top1==n-1){
        printf("Overflow\n");
    }
    else{
        top1++;
        stack1[top1]=x;
    }
}
   

void dequeue() {
    if (top1 == -1) {
        printf("Queue is empty\n");
    } else {
        while (top1 != -1) {
            stack2[top2] = stack1[top1];
            top2++;
            top1--;
        }
        popstack2();
        while (top2 != -1) {
            top1++;
            stack1[top1] =  stack2[top2];
            top1++;
            top2--;
        }
    }
}





void display(){
    if(top1==-1){
        printf("empty");
    }
    else{
    for(int i=0;i<=top1;i++){
        printf("%d\n",stack1[i]);
    }
}}

int main() {
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        int choice = 0;
        printf("Enter choice\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("Do you want to perform more operations? (y/n): ");
        scanf(" %c", &ch);
    }
    return 0;
}

