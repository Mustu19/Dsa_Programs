#include<iostream>
using namespace std;
class node
{
    int info;
    node* next;
    public:
    node()
    {
        info=0;
        next=NULL;
    }
    node(int d_info)
    {
        info=d_info;
        next=NULL;
    }
    void traverse()
    {
        node* tp=this;
        while(tp!=NULL)
        {
            cout<<tp->info<<endl;
            tp=tp->next;
        }
    }
    void append(node* new_node)
    {
        node *tp=this;
        while(tp->next!=NULL)
        {
            tp=tp->next;
        }
        tp->next=new_node;
    }
    void delete_node(node* A)
    {
        node* pr_tp=NULL;
        node* tp=this;
        while(tp!=NULL)
        {
            pr_tp=tp;
            tp=tp->next;
            if(tp==A)
            {
                pr_tp->next=tp->next;
            }
        }
   }
   void insertfirst(node* new_node_first)
   {
    node* tp=this;
    new_node_first->next=tp;
    tp=new_node_first;
   }
   void isnertnew(node* pre_node,node* new_node)
   {
    node* tp=this;
    while(tp!=NULL)
    {
        tp=tp->next;
        if(tp==pre_node)
        {
            new_node->next=tp->next;
            tp->next=new_node;
        }
    }
   }
};
int main()
{
    node* first=new node(3);
    cout<<"List of First Node:"<<endl;
    first->traverse();
    node* new_node=new node(5);
    first->append(new_node);
    node* node2=new node(7);
    new_node=new node(9);
    first->append(new_node);
    node* new_node1=new node(11);
    first->append(new_node1);
    cout<<"List after appending four nodes in last:"<<endl;
    first->traverse();
    first->delete_node(node2);
    cout<<"List after deleting third node:"<<endl;
    first->traverse();
    node* first1=new node(1);
    first->insertfirst(first1);
    cout<<"List after asding node before first node:"<<endl;
    first1->traverse();
    node* node3=new node(8);
    first1->isnertnew(new_node,node3);
    cout<<"List after adding node between any two nodes:"<<endl;
    first1->traverse();
    return 0;
}