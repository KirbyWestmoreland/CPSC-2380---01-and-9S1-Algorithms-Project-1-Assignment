#include<iostream>
#include<cstring>
#include<stack>
#include <cstdlib>

using namespace std;

// University of Arkansas at Little Rock
// Department of Computer Science
// CPSC 2380: Algorithms
// Spring 2024
// Project 1: Infix to Postfix Conversion, Bonus: evaluate arithmetic expressions
// for the results. This program is not a menu-driven.
// Due Date: April 11, 2024, Thursday
// Name: Kirby Westmoreland
// T-number: T00420650
// Description of the Program (2-3 sentences): This program converts infix
// arithmetic expressions to postfix. Each operator and operand is
// separated by at least one spaces
// Date Written:4/4/2024
// Date Revised:4/11/2024 1:51 AM


int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(char* str)
{
    // convert infix to postfix
    stack<char> st;
    string res = "";


    for (int i = 0; str[i] != '\0'; i++)
    {

        if (isdigit(str[i]))
            res += str[i];
        else if (str[i] == ' ')
            continue; // Ignore spaces

        // Character is an opening parenthesis, push it to the stack.
        else if (str[i] == '(')
            st.push('(');

        // Character is a closing parenthesis, pop stack until matching '(' is found.
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                char op = st.top();
                st.pop();
                res += op;
            }
            // Pop the '(' from the stack
            if (!st.empty() && st.top() == '(')
                st.pop();
        }


        else
        {
            // Pop operators from stack with higher or equal precedence and append to result.
            while (!st.empty() && precedence(str[i]) <= precedence(st.top()))
            {
                char op = st.top();
                st.pop();
                res += op;
            }
            // Push current operator onto the stack.
            st.push(str[i]);
        }
    }

    // Pop remaining operators from stack and add to result.
    while (!st.empty())
    {
        char x = st.top();
        st.pop();
        res += x;
    }

    return res;
}

int main()
{
    char* str = new char[80];
    while (true)
    {
        cout << "Enter an arithmetic equation ('control-c' to exit):" << endl;
        cin.getline(str, 80);

        if (strcmp(str, "control-c") == 0) {
            break;
        }

        cout << InfixToPostfix(str) << endl;
    }

    delete[] str;

    return 0;
}