/*Design Circular Queue*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;
int capacity;

int isFull()
{
    return ((rear + 1) % capacity == front);
}

int isEmpty()
{
    return (front == -1);
}

void insertFront(int x)
{
    if(isFull())
    {
        printf("Deque Full\n");
        return;
    }

    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + capacity) % capacity;
    }

    deque[front] = x;
}

void insertRear(int x)
{
    if(isFull())
    {
        printf("Deque Full\n");
        return;
    }

    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % capacity;
    }

    deque[rear] = x;
}

void deleteFront()
{
    if(isEmpty())
    {
        printf("Deque Empty\n");
        return;
    }

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }
}

void deleteRear()
{
    if(isEmpty())
    {
        printf("Deque Empty\n");
        return;
    }

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + capacity) % capacity;
    }
}

int getFront()
{
    if(isEmpty()) return -1;
    return deque[front];
}

int getRear()
{
    if(isEmpty()) return -1;
    return deque[rear];
}

void display()
{
    if(isEmpty())
    {
        printf("Deque Empty\n");
        return;
    }

    int i = front;

    while(1)
    {
        printf("%d ", deque[i]);

        if(i == rear)
            break;

        i = (i + 1) % capacity;
    }

    printf("\n");
}

int main()
{
    capacity = 5;

    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);

    display();

    deleteFront();
    deleteRear();

    display();

    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());

    return 0;
}