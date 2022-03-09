#include<iostream>
#include<stack>
using namespace std;

class queue
{
    stack<int> st1;
    stack<int> st2;

    public:


    void push(int x)
    {
        st1.push(x);
    }


    int pop()
    {
      if(st1.empty() && st2.empty())
      {
        cout<<"Queue is empty"<<endl;
        return -1;
      }

      if(st2.empty())
      {
        while(!st1.empty())
        {
          st2.push(st1.top());
          st1.pop();
        }
      }

      int topEle = st2.top();
      st2.pop();
      return topEle;
    }

    bool empty()
    {
        if(st1.empty() && st2.empty())
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

    cout<<q.pop()<<endl; // 1

    q.push(5);
    cout<<q.pop()<<endl; // 2

    cout<<q.pop()<<endl;  // 3
    cout<<q.pop()<<endl;  //4
    //cout<<q.pop()<<endl; //5
    //cout<<q.pop()<<endl;  // queue is empty

    cout<<q.empty()<<endl;   // now q  is not empty  // 0 
    


     
    




    return 0;
}