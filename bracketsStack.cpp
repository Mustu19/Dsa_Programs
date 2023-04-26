#include<iostream>
#include<string>
#include<stack>
using namespace std;

int bracketBalanced(string exp){
    stack<char> st ;
    for (int i = 0; i < exp.length(); i++)
    {
        if(st.empty()){
            st.push(exp[i]) ;
        }
        else if((st.top()=='(' && exp[i]==')') || (st.top()=='[' && exp[i]==']') || (st.top()=='{' && exp[i]=='}')){
            st.pop();
        }
        else{
            st.push(exp[i]);
        }
    }
    if(st.empty()){
        return true;
    }
    return false ;
    
}

int main()
{
 string s;
 cout<<"Write a Expression:" ;
 cin>>s ;
 if(bracketBalanced(s)){
    cout<<"Valid String" ;
 }
 else{
    cout<<"Invalid String" ;
 }
 return 0;
}