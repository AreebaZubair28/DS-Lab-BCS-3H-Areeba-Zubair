#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Skip spaces
        if (c == ' ')
            continue;

        // If operand, add to postfix
        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';  // space to separate numbers
        }

        // If '(' push to stack
        else if (c == '(') {
            st.push(c);
        }

        // If ')' pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.pop(); // remove '('
        }

        // If operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                // For right-associative operator '^', use strict greater precedence
                if (c == '^' && precedence(st.top()) == precedence(c))
                    break;
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}

// Evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (c == ' ')
            continue;

        // If number
        if (isdigit(c)) {
            int num = 0;
            // Handle multi-digit numbers
            while (i < postfix.length() && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }

        // If operator
        else if (isOperator(c)) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
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

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
