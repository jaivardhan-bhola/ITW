#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* rear=0;
struct node* front=0;


void enqueue(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    printf("enter data to be queued\n");
    scanf("%d",&newnode->data);
    if(rear==0){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct node* temp=front;
    if(rear==0){
        printf("list is empty\n");
    }
    else{
        front=front->next;
        free(temp);
    }

}

void display(){
    struct node* temp=front;
    while(temp!=0){
        printf("Element: %d\n",temp->data);
        temp=temp->next;
    }

}

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




