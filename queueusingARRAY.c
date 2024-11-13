#include<stdio.h>

#define n 5
int queue[n];
int rear = -1;
int front = -1;

void enqueue() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);
    if (rear == n - 1) {
        printf("Overflow\n");
    } else if (rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (rear == front) {
        printf("Dequeued element is %d\n", queue[front]);
        rear = front = -1;
    } else {
        printf("Dequeued element is %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

int main() {
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        int choice = 0;
        printf("Enter choice\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.PEEK\n");
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
            case 4:
                peek();
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
