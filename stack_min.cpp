#include <iostream>
#include<limits.h>
using namespace std;
#define STACK_SIZE 100

class stac
{
public:
void push(int item)
{
    if(top>=STACK_SIZE-1)
    {
        cout<<"Full"<<endl;
        return;
    }
    else
    {
        if(item<min1)
        {
            min2 = min1;
            min1=item;
        }
        s[++top]=item;
        return;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"Empty"<<endl;
        return;
    }
    else
    {
        if(s[top]==min1)
        {
            min1=min2;
        }
        top--;
        return;
    }
}

void mini()
{
    if(top==-1)
    {
        cout<<"no minimum"<<endl;
        return;
    }
    else
    {
        cout<<min1<<endl;
    }
}
private:
int min1 = INT_MAX;
int min2;
int s[STACK_SIZE];
int top = -1;
};
int main()
{
   
    stac s1;
    
s1.push(5);
s1.push(2);
s1.push(9);
s1.push(1);
s1.push(24);
s1.push(-1);
s1.push(-87);
s1.push(23);
s1.mini();
    
    return 0;
}
