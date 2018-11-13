//evaluate postfix
#include<iostream>
#include<math.h>
using namespace std;
int stack[50];
char postfix[50];
int top=-1,a=0;
void push(int res)
{
 top++;
 stack[top]=res;
 // cout<<stack[top]<<" ";
}
int pop()
{
 a=stack[top];
 top--;
  return a;
}
int main()	
{
  cout<<"Enter the postfix ";
  char ch;
  int res;
  int i=0;
  cin>>ch;
  while(ch!='$')
  {
    postfix[i]=ch;
    cin>>ch;
    i++;
  }
  postfix[i]='\0';
    i=0;
    while(postfix[i]!='\0')
   {
     if(isdigit(postfix[i]))
      {
        res=postfix[i]-48;    
      }
     else
      {
         int a=pop();
         int b=pop();
           switch(postfix[i])
            {
              case '^':
               { res=pow(b,a); break; }
              case '*':
               { res=b*a; break; }
              case '/':
               { res=b/a; break; }
              case '+':
               { res=b+a; break; }
              case '-':
               { res=b-a; break; }
            }
       }
      push(res);
      i++; 
   }
 // cout<<top;
  cout<<stack[top];
}
