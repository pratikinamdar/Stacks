/* This is a usual stack implementation in C++ with a small modification
 I have added a function mini() that gives me the smallest element in the stack at anytime in O(1) time unless the stack is empty
 but this has an O(n) space complexity in the worst case for storing all the minimun elements found in another stack*/

#include <iostream>
#include<limits.h>
using namespace std;
#define STACK_SIZE 100
class stac
{
    private:
    int top = -1;
    int min = INT_MAX;
    int s[STACK_SIZE];
    int mini[STACK_SIZE];
    int top_mini = -1;
public:
void push(int item)
{
 if(top==STACK_SIZE-1)
 {
     cout<<"Full"<<endl;
     return;
 }
 else
 {
     if(item<min)
     {
         min = item;
         mini[++top_mini] = min;
     }
     s[++top] = item;
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
        if(s[top] == min)
        {
            min = mini[--top_mini];
        }
        top = top-1;
        return;
    }
}
void minimum()
{
     if(top==-1)
    {
        cout<<"Empty"<<endl;
        return;
    }
    
    else
    {
        cout<<"Min is: "<<min;
        return;
    }
    
}

    
};



int main()
{
    stac s1;
    
    s1.push(100);
    
    s1.push(2);
    s1.push(3);
    s1.push(4);
  s1.pop();
  s1.pop();
  s1.pop();
    s1.push(5);
     s1.pop();
    s1.push(6);
    s1.push(7);
    s1.push(8);
     s1.minimum();
    return 0;
}
