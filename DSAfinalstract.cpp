#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
    int top = -1;
    char stackstore[100];

public:
    Stack()
    {
    }

    void push(char ch)
    {
        if (top < 99)
        {
            top++;
            stackstore[top] = ch;
        }
        else
        {
            cout << "Stack Overflow\n";
        }
    }

    char pop()
    {
        if (top > -1)
        {
            char value = stackstore[top];
            top--;
            return value;
        }
        else
        {
            cout << "Stack Underflow\n";
            return '\0';
        }
    }

    bool empty()
    {
        return top == -1;
    }
};

bool check(string word)
{
    Stack thestack;

    for (char c : word)
    {
        if (c == '(')
        {
            thestack.push(c);
        }
        else if (c == ')')
        {
            if (thestack.empty())
            {
                return false;
            }

            thestack.pop();
        }
    }

    // After scanning the whole string
    if (thestack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << "Enter the expression:\n";

    string theWord;
    getline(cin, theWord);

    if (check(theWord))
    {
        cout << "The brackets are balanced.\n";
    }
    else
    {
        cout << "The brackets are NOT balanced.\n";
    }

    return 0;
}