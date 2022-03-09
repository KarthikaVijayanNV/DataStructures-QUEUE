#include<iostream>
#include<queue>
using namespace std;

class stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    stack()
    {
        N= 0;
    }

    void push(int x)
    {
        q2.push(x);
 
        N++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp; 
    } 

    void pop()
    {
        q1.pop();
        N--;
    }  

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return N;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<"Current size: "<<st.size()<<endl; //4

    cout<<st.top()<<endl; //4
    st.pop();

    cout<<st.top()<<endl; //3
    st.pop();
  
    cout<<st.top()<<endl; //2
    st.pop();

    cout<<st.top()<<endl; //1
    st.pop();

    cout<<"Current size: "<<st.size()<<endl; // 0


   






    return 0;
}