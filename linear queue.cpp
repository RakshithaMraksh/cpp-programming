// Linear Queue implementation
#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int *arr;
    int n;

public:
    Queue(int n )
    {
        front = -1;
        rear = -1;
        this->n = n;
        arr = new int[n];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == n - 1)
            return true;
        else
            return false;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    int dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }

    void display()
    {
        cout << "value of Queue:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size, value;
    cout << "Enter size of queue:" << endl;
    cin >> size;
    Queue q(size);
    int choice;
    bool flag = true;
    while (flag)
    {
        cout << "Enter choice: 0.exit() 1.Enqueue()  2.dequeue()  3.isEmpty()  4.isFull()  5.display()    7.clear screen :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
        exit(0);
            break;
        case 1:
            cout << "Enter element to enqueue" << endl;
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            cout << "dequeued value:" << q.dequeue() << endl;
            break;
        case 3:
            if (q.isEmpty())
                cout << "queue is empty:" << endl;
            else
                cout << "queue is not empty" << endl;
            break;
        case 4:
            if (q.isFull())
                cout << "queue is full" << endl;
            else
                cout << "queue is not full" << endl;
            break;
        case 5:
            q.display();
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter valid choice" << endl;
        }
    }
    return 0;
}