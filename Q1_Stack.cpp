#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int stackArr[MAX_SIZE];
int top = -1;

void push(int val)
{
    if (top >= MAX_SIZE - 1)
    {
        cout << "Stack Overflow! Cannot insert " << val << endl;
        return;
    }
    stackArr[++top] = val;
    cout << val << " inserted successfully." << endl;
}

void pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow! Stack is empty." << endl;
        return;
    }
    cout << stackArr[top--] << " removed successfully." << endl;
}

void peek()
{
    if (top < 0)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top element: " << stackArr[top] << endl;
}

void display()
{
    if (top < 0)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
    {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, value;
    do
    {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push  2. Pop  3. Peek\n4. Display  5. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}
