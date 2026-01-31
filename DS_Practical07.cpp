#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

bool isOperand(char c){
    return (isalnum(c));
}

string infixToPostfix(string s){
    stack<char> st;
    string res="";
    for(char c : s){
        if(isOperand(c))
            res += c;
        else if(c=='(')
            st.push(c);
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(c) <= prec(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    for(char &c : s){
        if(c=='(') c=')';
        else if(c==')') c='(';
    }
    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

string postfixToInfix(string s){
    stack<string> st;
    for(char c : s){
        if(isOperand(c))
            st.push(string(1,c));
        else{
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }
    return st.top();
}

string prefixToInfix(string s){
    stack<string> st;
    reverse(s.begin(), s.end());
    for(char c : s){
        if(isOperand(c))
            st.push(string(1,c));
        else{
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }
    return st.top();
}

string prefixToPostfix(string s){
    stack<string> st;
    reverse(s.begin(), s.end());
    for(char c : s){
        if(isOperand(c))
            st.push(string(1,c));
        else{
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push(a + b + c);
        }
    }
    return st.top();
}

string postfixToPrefix(string s){
    stack<string> st;
    for(char c : s){
        if(isOperand(c))
            st.push(string(1,c));
        else{
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push(c + a + b);
        }
    }
    return st.top();
}

int main(){
    int ch;
    string exp;

    while(true){
        cout << "\n--- Expression Conversion Menu ---\n";
        cout << "1. Infix to Prefix\n";
        cout << "2. Infix to Postfix\n";
        cout << "3. Prefix to Infix\n";
        cout << "4. Postfix to Infix\n";
        cout << "5. Prefix to Postfix\n";
        cout << "6. Postfix to Prefix\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if(ch==7) break;

        cout << "Enter expression: ";
        cin >> exp;

        switch(ch){
            case 1: cout << "Prefix:  " << infixToPrefix(exp); break;
            case 2: cout << "Postfix: " << infixToPostfix(exp); break;
            case 3: cout << "Infix:   " << prefixToInfix(exp); break;
            case 4: cout << "Infix:   " << postfixToInfix(exp); break;
            case 5: cout << "Postfix: " << prefixToPostfix(exp); break;
            case 6: cout << "Prefix:  " << postfixToPrefix(exp); break;
            default: cout << "Invalid choice!";
        }
        cout << "\n";
    }
    return 0;
}