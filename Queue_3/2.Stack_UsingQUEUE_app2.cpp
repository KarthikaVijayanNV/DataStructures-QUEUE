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
        N = 0;
    }

    void pop()  // costly
    {
        if(q1.empty())
        {
            return ;
        }

        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop(); // one element remained in Q1 is poped
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void push(int x)  // easy
    {
        q1.push(x);
        N++;
    }

    int top()
    {
        if(q1.empty())
        {
            return -1;
        }

        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
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

    cout<<"Current size: "<<st.size()<<endl;  //4

    cout<<st.top()<<endl; //4
    st.pop();

    cout<<st.top()<<endl; //3
    st.pop();

    cout<<st.top()<<endl; //2
    st.pop();

    cout<<"Current size: "<<st.size()<<endl; // 1

    return 0;
}