#include<iostream>
using namespace std;

#define n 50

class queue
{
  int* arr;
  int front;
  int back;

  public:
  queue()
  {
    arr = new int[n];
    front =-1;
    back = -1;
  }  


  void Enqueue(int x)  // push
  {
    if(back == n-1)
    {
       cout<<"Queue Overflow- full"<<endl;
       return;
    }

    back++;
    arr[back] = x;


    if(front == -1)
    {
        front++;
    }
  }
   

   void Dequeue()
   {
       if(front == -1  ||  front >back)
       {
           cout<<"Queue is underflow - no element to delete"<<endl;
           return ;
       }

       front++;
   }

   int peek()
   {
      if(front == -1  ||  front >back)
       {
        cout<<"Queue underflow - no element in queue"<<endl;
        return -1 ;
       }

       return arr[front];

   }

    bool empty()
   {
     
      if(front == -1  ||  front >back)
       {
          return true;
       }
      return false;
   }

};




int main()
{
   queue q;
   q.Enqueue(1);
   q.Enqueue(2);
   q.Enqueue(3);
   q.Enqueue(4);

   
   cout<<q.peek()<<endl; //1
    q.Dequeue();
  
   cout<<q.peek()<<endl; //2
    q.Dequeue();

    cout<<q.peek()<<endl;//3
    q.Dequeue();

    cout<<q.peek()<<endl; //4
    q.Dequeue();

   

    cout<<q.empty();  // true ...queue is empty


    return 0;
}