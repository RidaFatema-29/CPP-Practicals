#include<iostream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

stack<char> str;
string og;

void reverse_palindrome(){
    int len = og.length();
    for(int i=0;i<len;i++){
        cout<<"\nElement Pushed into the Stack : "<<og[i];
        str.push(og[i]);
    }
    cout<<"\n\nPopping the elements for reversing the string : ";
    string rev="";
    while(!str.empty()){
        cout<<"\n "<<str.top()<<" Popped ";
        rev+=str.top();
        str.pop();
    }
    cout<<"\n\nReversed String is : "<<rev;

    //Palindrome 
    if(og==rev){
        cout<<"\nString is Palindrome.";
    }
    else{
        cout<<"\nString is not Palindrome.";
    }
}

int main(){
    cout<<"\nEnter a String : ";
    cin>>og;
    reverse_palindrome();
    
}