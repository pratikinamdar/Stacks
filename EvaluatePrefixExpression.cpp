// This program evaluates the reuslt of a given prefix expression. This runs in O(n) time and uses stack space for expression evaluation.
// This code supports 6 binary operators.
// Also this code supports operands having multiple digits.
//Constraint: Provide input only as space separated operands and operators.

#include <iostream>
#include<stack>
#include <math.h>
using namespace std;



int toInteger(string str)
{
int sign =1; int result = 0;

for(int i=0; i<str.length(); i++)
	{
	  if(str[i] == '-')
	  {
	    sign =-1;
	  }
	  else
	  {
	    result = result *10 + (str[i]-'0');
	  }
	}
	
	return (sign * result);
}

bool isDigit(char a)
{
 if(a-'0'<=9 && a-'0'>=0) return true;
 else return false;
}

int evalPreFix(string a)
{
stack <int> s;
int op1, op2;
int res;
  for(int i=a.length()-1;i>=0;i--)
  {
    if(a[i]=='+' ||a[i]=='*' || a[i]=='/' || a[i]=='-' || a[i]=='^' || a[i]=='%')
	{
	  op1 = s.top();
	  s.pop();
	  op2= s.top();
	  s.pop();
	  switch(a[i])
	  {
	     case '+': res=op1+op2; break;
             case '-': res=op1-op2; break;
             case '*': res=op1*op2; break;
             case '/': res=op1/op2;   break;
             case '%': res=op1%op2;   break;
             case '^': res=pow(op1,op2);   break;


	  }
	   s.push(res);
	   if(a[i-1]==' ') i--;
	   
	}
	else if(isDigit(a[i]))
	{
	   int j= i;
	   while(a[j]!=' ')
	   {
	     j--;
	   }
	   string str="";
	   for(int k =j+1;k<=i;k++)
	   {
	      
		  str=str+a[k];
	   }
	   s.push(toInteger(str));
	   i = j;
	}
	else
	{
		cout<<"Invalid postfix string\n";
	}
  }
    
  return s.top();
}


int main()
{
   cout<<evalPreFix("+ * 5 6 22");
    return 0;
}
