#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }

};

class queue
{
    public:
    node* front;
    node* back;

    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        node* n = new node(x);
     
       if(front == NULL)
       {
           front =n;
           back =n;
           return;
       } 

        back->next = n;
        back = n;
    }

    void pop()
    {
        if(front == NULL)
        {
            cout<<"Queue undeflow"<<endl;
            return ;
        }

        node* todelete = front;
        front = front ->next;
        delete todelete;
    }


    int peek()
    {
        if(front == NULL)
        {
          cout<<"No element in the queue"<<endl;
           return -1 ;
        }

        return front->data;
    }

    bool empty()
    {
        if(front == NULL)
        {
           return true;
        }

        return false;
    }
};



int main()
{

   queue q;
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);

   cout<<q.peek()<<endl; // 1
   q.pop();

   cout<<q.peek()<<endl; //2
   q.pop();
   
   cout<<q.peek()<<endl; // 3
   q.pop();

   cout<<q.peek()<<endl; //4
   q.pop();


  cout<<q.empty(); // true it is empty
    return 0;
}