#include<iostream>
#include<string.h>
using namespace std;
class my_stack{

    int arr[3];
    int top;

    public:
        my_stack(){
            top = -1;    
        }
        void push(int val){

            if(top >= 2){
                cout<<"stack overflow" ;
            }else{
                top++ ;
                arr[top] = val ;
            }
        }
        int pop(){  
            if(top <=-1){
                cout<<"stack underflow" ;
            }
            else{
                int temp = arr[top] ;
                top--;
                return temp;
            }  
            return 0 ;
        }
        void display(){
            for (int i = 0 ; i < 3 ; i++)
            {
                cout<<arr[i]<<" " ;
            }
            cout<<endl ;  
        }
};

int main()
{
 my_stack st;
 st.push(6);
 st.push(8);
 st.push(7);
 st.display();
 st.push(67);
 return 0;
}