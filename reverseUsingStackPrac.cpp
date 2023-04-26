#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

void reverseString(string str){
    stack<string> st ;
    
    for (int i = 0; i < str.length(); i++)
    {
        string s = "" ;
        while (str[i]!=' ' && i < str.length())
        {
            s += str[i] ;
            i++ ;
        }
        st.push(s) ;
    }
    while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop() ;
        }
    
}
int main()
{
 string st = "why are you looking at me?" ;
 reverseString(st);
 return 0;
}