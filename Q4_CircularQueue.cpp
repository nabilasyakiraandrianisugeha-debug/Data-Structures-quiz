#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int cQueue[MAX_SIZE];
int frontIdx = -1, rearIdx = -1;

bool isFull()
{
    return (rearIdx + 1) % MAX_SIZE == frontIdx;
}

bool isEmpty()
{
    return frontIdx == -1;
}

void enqueue(int val)
{
    if (isFull())
    {
        cout << "Circular Queue Overflow! Cannot insert " << val << endl;
        return;
    }
    if (isEmpty())
    {
        frontIdx = 0;
    }
    rearIdx = (rearIdx + 1) % MAX_SIZE;
    cQueue[rearIdx] = val;
    cout << "Enqueued: " << val << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Circular Queue Underflow! Queue is empty." << endl;
        return;
    }
    cout << "Dequeued: " << cQueue[frontIdx] << endl;
    if (frontIdx == rearIdx)
    {
        frontIdx = rearIdx = -1;
    }
    else
    {
        frontIdx = (frontIdx + 1) % MAX_SIZE;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    int i = frontIdx;
    while (true)
    {
        cout << cQueue[i] << " ";
        if (i == rearIdx)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

int main()
{
    int choice, value;
    do
    {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue\n3. Display  4. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}
