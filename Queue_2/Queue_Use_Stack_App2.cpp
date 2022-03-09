#include<iostream>
#include<stack>
using namespace std;

class queue
{
    stack<int> st1;

    public:


    void push(int x)
    {
        st1.push(x);
    }


    int POPoperation()    // compiler will get confusion so name changed
    {
        if(st1.empty())   // no elements
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }

         int x = st1.top();   // only one element
         st1.pop(); 

        if(st1.empty())
        {
            return x;
        }

        int result = POPoperation();  // recursive call  if more than one element
        st1.push(x);
        return result;
    }

    bool empty()
    {
        if(st1.empty())
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

    cout<<q.POPoperation()<<endl; // 1

    q.push(5);
    cout<<q.POPoperation()<<endl; // 2

    cout<<q.POPoperation()<<endl;  // 3
    cout<<q.POPoperation()<<endl;  //4
    //cout<<q.pop()<<endl; //5
    //cout<<q.pop()<<endl;  // queue is empty

    cout<<q.empty()<<endl;   // now q  is not empty  // 0 
    


     
    




    return 0;
}