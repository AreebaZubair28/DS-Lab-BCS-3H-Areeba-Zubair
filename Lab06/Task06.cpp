#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Infix to Postfix (helper for infix to prefix)
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c == ' ')
            continue;

        // Operand
        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        }

        // Opening bracket
        else if (c == '(') {
            st.push(c);
        }

        // Closing bracket
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.pop();
        }

        // Operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) > precedence(c)) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            // handle right associativity of '^'
            while (!st.empty() && precedence(st.top()) == precedence(c) && c != '^') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}

// Infix to Prefix
string infixToPrefix(string infix) {
    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Swap '(' and ')'
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Convert reversed infix to postfix
    string postfix = infixToPostfix(infix);

    // Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Evaluate Prefix expression
int evaluatePrefix(string prefix) {
    stack<int> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (c == ' ')
            continue;

        // Operand (handle multi-digit)
        if (isdigit(c)) {
            int num = 0;
            int base = 1;

            while (i >= 0 && isdigit(prefix[i])) {
                num = num + (prefix[i] - '0') * base;
                base *= 10;
                i--;
            }
            i++;
            st.push(num);
        }

        // Operator
        else if (isOperator(c)) {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            int result = 0;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
            }
            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression (e.g., 3+4*(2-1)): ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
