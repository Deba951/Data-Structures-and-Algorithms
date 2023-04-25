#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int** display_Queue(int n, int q[50][50], int rear[50], int front[50], int  *p[52])
{
    int check = -1;
     for (int i = 0; i < n; i++)
    {
        rear [i] = *(p[0] + i);
    }
    for (int i = 0; i < n; i++)
    {
        front [i] = *(p[1] + i);
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n; j ++)
        {
            q[i][j] = *(p[i] + j);
        }
    }
    cout << "The priority queue is displaying :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = front[i]; j != rear[i]; j = (j + 1) % n)
        {
            if (q[i][j])
            {
                cout << "\t " << q[i][j];
                check = 1;
            }
        }
        if (q[i][rear[i]])
        {
            cout << "\t" << q[i][rear[i]];
            check = 1;
        }
    }
    if (check == -1)
    {
        cout << "The PRIORITY QUEUE is empty!!" << endl;
    }
    cout << endl;
    p[0] = rear;
    p[1] = front;
    for (int i = 2; i < n; i ++)
    {
        p[i] = &q[i][0];
    }
    return p;
}
int** dequeue (int n, int q[50][50], int rear[50], int front[50], int  *p[52])
{
     for (int i = 0; i < n; i++)
    {
        rear [i] = *(p[0] + i);
    }
    for (int i = 0; i < n; i++)
    {
        front [i] = *(p[1] + i);
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n; j ++)
        {
            q[i][j] = *(p[i] + j);
        }
    }
    int check = -1;
    for (int i = 0; i < n; i ++)
    {
        check = 0;
        for (int j = 0; j < n; j ++)
        {
            if (q[i][j] != 0 && j == n-1)
            {
                cout << q[i][j] << " " << "is being deleted" << endl;
                q[i][j] = 0;
                front[i] = -1;
                check = 1;
                break;
            }
            else if (q[i][j] != 0 && j != n-1)
            {
                cout << q[i][j] << " " << "is being deleted" << endl;
                q[i][j] = 0;
                front[i] = front[i] + 1;
                check = 1;
                break;
            }
        }
        if (check == 1)
        {
          break;
        }
    }
    if (check == 0)
    {
        cout << "The PRIORITY QUEUE is already empty!! UNDERFLOW!!" << endl;
    }
    p[0] = rear;
    p[1] = front;
    for (int i = 2; i < n; i ++)
    {
        p[i] = &q[i][0];
    }
    return p;
}
int **enqueue (int n, int q[50][50], int rear[50], int front[50], int  *p[52])
{
    int val, prio, choice = 1;
    for (int i = 0; i < n; i++)
    {
        rear [i] = *(p[0] + i);
    }
    for (int i = 0; i < n; i++)
    {
        front [i] = *(p[1] + i);
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n; j ++)
        {
            q[i][j] = *(p[i] + j);
        }
    }
    cout << "Enter the value to insert except zero: " << endl;
    cin >> val;
    cout << "Enter the priority number : " << endl;
    cin >> prio;
    int index = prio - 1;
    //cout << rear[index] << " " << front[index] << "\n";
    if (rear[index] == -1 && front[index] == -1)
    {
        rear[index] = 0;
        front[index] = 0;
        q[index][0] = val; 
    }
    else if ((rear[index] == n-1  && front[index] == 0) || (front[index] == rear[index] + 1))
    {
        cout << "Overflow" << endl;
    }
    else if (rear[index] == n-1)
    {
        rear[index] = 0;
        q[index][0] = val;
    }
    else
    {
        rear[index] = rear[index] + 1;
        q[index][rear[index]] = val;
    }
    p[0] = rear;
    p[1] = front;
    for (int i = 2; i < n; i ++)
    {
        p[i] = &q[i][0];
    }
    return p;
}
int main()
{
    int n, choice = 1;
    int **p1;
    cout << "Enter the highest priority number :" << endl;
    cin >> n;
    int q[50][50], rear[50], front[50], *p[52];
    fill(rear, rear + n, -1);
    fill(front, front + n, -1);
    p[0] = rear;
    p[1] = front;
    for (int i = 2; i < n; i ++)
    {
        p[i] = &q[i][0];
    }
    while (choice)
    {
        cout << "Press 1 for Insertion : " << endl;
        cout << "Press 2 for deletion : " << endl;
        cout << "Press 3 for display : " << endl;
        cout << "Press 0 to end the program : " << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;
        if (choice == 1)
        {
            p1 = enqueue(n, q, rear, front, p);
        }
        else if (choice == 2)
        {
            p1 = dequeue(n, q, rear, front, p);
        }
        else if (choice == 3)
        {
            p1 = display_Queue(n, q, rear, front, p);
        }
        else if (choice == 0)
        {
            cout << "The program is ended" << endl;
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}




/*
#include <stdio.h>
int* enqueue_front (int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    int x;
    printf("\n Enter the value : ");
    scanf("%d",&x);
    if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        arr[front] = x;
    }
    else if((rear == n-1 && front == 0) || front == rear + 1)
    {
        printf("\n Overflow");
    }
    else if (front == 0)
    {
        front = n-1;
        arr[front] = x;
    }
    else
    {
        front --;
        arr[front] = x;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
int* enqueue_rear(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    int x;
    printf("\n Enter the value : ");
    scanf("%d",&x);
    if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        arr[rear] = x;
    }
    else if((rear == n-1 && front == 0) || front == rear + 1)
    {
        printf("\n Overflow");
    }
    else if (rear == n-1)
    {
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear ++;
        arr[rear] = x;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
int* dequeue_rear(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Undeflow");
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else if (rear == 0)
    {
        rear = n-1;
    }
    else
    {
        rear --;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
int* dequeue_front(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Undeflow");
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else if (front == n-1)
    {
        front = 0;
    }
    else
    {
        front ++;
    }
    a[0] = rear;
    a[1] = front;
    return a;
}
void display_deque(int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Empty deque");
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % n)
        {
            printf("\t %d ", arr[i]);
        }
        printf("\t %d ", arr[rear]);
    }
}
void get_rear (int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Empty deque");
    }
    else
    {
        printf("\n The rear value is \t %d", arr[rear]);
    }
}
void get_front (int n, int arr[n], int rear, int front, int a[2])
{
    rear = a[0];
    front = a[1];
    if (rear == -1 && front == -1)
    {
        printf("\n Empty deque");
    }
    else
    {
        printf("\n The front value is \t %d", arr[front]);
    }
}
int main()
{
    int n, rear = -1, front = -1, choice = 1;
    int a[2];
    a[0] = -1;
    a[1] = -1;
    printf("Enter the maximum size of the circular array : ");
    scanf("%d", &n);
    int arr[n];
    while (choice != 0)
    {
        printf("\n Press 1 for ENQUEUE from FRONT");
        printf("\n Press 2 for ENQUEUE from REAR");
        printf("\n Press 3 for DEQUEUE from FRONT");
        printf("\n Press 4 for DEQUEUE from REAR");
        printf("\n Press 5 for GETTING the FRONT");
        printf("\n Press 6 for GETTING the REAR");
        printf("\n Press 7 for displaying the deque");
        printf("\n Enter 0 for ENDING of the PROGRAM");
        printf ("\n Enter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int *p1;
            p1 = enqueue_front (n, arr, rear, front, a);
        }
        else if (choice == 2)
        {
            int *p2;
            p2 = enqueue_rear (n, arr, rear, front, a);
        }
        else if (choice == 3)
        {
            int *p3;
            printf("\n The front value is deleted if not Underflow");
            p3 = dequeue_front (n, arr, rear, front, a);
        }
        else if (choice == 4)
        {
            int *p4;
            printf("\n The rear value is deleted if not Underflow");
            p4 = dequeue_rear (n, arr, rear, front, a);
        }
        else if (choice == 5)
        {
            get_front (n, arr, rear, front, a);
        }
        else if (choice == 6)
        {
            get_rear (n, arr, rear, front, a);
        }
        else if (choice == 7)
        {
            display_deque(n, arr, rear, front, a);
        }
        else if (choice == 0)
        {
            printf("\n The program is ended");
        }
        else
        {
            printf("\n WRONG CHOICE");
        }
    }
    return 0;
}
*/