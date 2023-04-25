#include <bits/stdc++.h>
using namespace std;
int* enqueue (int rear, int front, int q[20], int arr[2])
{
    int x;
    rear = arr[0];
    front = arr[1];
    cout << "Enter an element to be inserted :"<< endl;
    cin >> x;
    if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        q[rear] = x;
        cout << "Enqueue is done" << endl;
    }
    else if ((rear + 1) % 20 == front)
    {
        cout << "Sorry, Overflow"<< endl;
    }
    else
    {
        rear = (rear + 1) % 20;
        q[rear] = x;
        cout << "Enqueue is done" << endl;
    }
    arr[0] = rear;
    arr[1] = front;
    return arr;
}
int* dequeue (int rear, int front, int q[20], int arr[20])
{
    rear = arr[0];
    front = arr[1];
    if (rear == -1 && front == -1)
    {
        cout << "Underflow" << endl;
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
        cout << "Dequeue is done" << endl;
    }
    else
    {
        cout << "The dequeued element is" << q[front] << endl;
        front = (front + 1) % 20;
        cout << "Dequeue is done" << endl;
    }
    arr[0] = rear;
    arr[1] = front;
    return arr;
} 
int* display_queue(int rear, int front, int q[20], int arr[20])
{
    rear = arr[0];
    front = arr[1];
    int i = front;
    if (rear == -1 && front == -1)
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        cout << "Displaying the queue" << endl;
        while (i != rear)
       {
            cout << "\t" << q[i];
            i = (i + 1) % 20;
       }
       cout << "\t" << q[rear];
       cout << endl;
    }
    return arr;
}
int main()
{
    int q[20];
    int front = -1, rear = -1;
    int c = 1;
    int arr[2];
    arr[0] = rear;
    arr[1] = front;
    int *p;
    p = arr;
    do{
        cout << "Enter 1 for enqueue and 2 for dequeue and 3 for display" << endl;
        cin >> c;
        if (c == 1)
        {
            p = enqueue(rear, front, q, p);
        }
        else if (c == 2)
        {
            p = dequeue(rear, front, q, p); 
        }  
        else if (c == 3)
        {
            p = display_queue(rear, front, q, p);
        } 
        else
        {
            cout << "Program is ended"<< endl;
        }  
    }while(c == 1 || c == 2 || c == 3);
    return 0;
}