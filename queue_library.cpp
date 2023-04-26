#include<iostream>
#include<queue>
using namespace std;
int main()
{
 queue<int> q;
 q.push(2);
 q.push(4);
 q.push(6);
 cout<<q.front()<<" "<<q.back();
 q.pop();
 q.pop();
 cout<<q.front()<<" "<<q.back();
 return 0;
}