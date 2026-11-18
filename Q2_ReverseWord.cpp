#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cout << "Enter a word: ";
    cin >> word;

    int n = word.length();
    char charStack[100];
    int top = -1;

    // Push setiap karakter dari kiri ke kanan
    for (int i = 0; i < n; i++)
    {
        if (top < 99)
        {
            charStack[++top] = word[i];
        }
    }

    cout << "\nOriginal word: " << word << endl;
    cout << "Reversed word: ";

    // Pop semua karakter untuk membalik urutan
    while (top >= 0)
    {
        cout << charStack[top--];
    }
    cout << endl;

    return 0;
}
