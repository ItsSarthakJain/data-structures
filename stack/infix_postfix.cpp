//infix to postfix conversion
#include<iostream>
#include<string.h>
using namespace std;
char stack[50];
char postfix[50];
int a=0,top=-1;
int prec(char in)
{
  if(in=='^')
   return 3;
  else if(in=='/'||in=='*')
   return 2;
  else if(in=='+'||in=='-')
   return 1;
  else
   return 0;
}
void push(char in)
{
  top++;
  stack[top]=in;


}
void insert_postfix(char in)
{
 if(in!=')'&&in!='(')
  { postfix[a]=in;
  a++;  }
}
void pop()
{
  insert_postfix(stack[top]);
  top=top-1;
}
void show()
{
 postfix[a]='\0';
  int i=0;
  cout<<endl;
  while(postfix[i]!='\0')
   {
     cout<<postfix[i];
    i++;
   }
}
int main()
{
  char infix[50];
   int p=0;
  char ch;
 top++;
 stack[top]='(';
  cin>>ch;
  while(ch!='$')
  {

   infix[p]=ch;
      cin>>ch;
   p++;
  }
  infix[p]=')';
  infix[p+1]='\0';
   int i=0;
   while(infix[i]!='\0')
   {
     if(isalpha(infix[i]))
      {  
        insert_postfix(infix[i]);
      }
     else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
      {
         if(prec(infix[i])>(prec(stack[top])))
           {
             push(infix[i]);
           }
         else if((prec(infix[i]))<=prec(stack[top]))
           {
            while(prec(infix[i])<=prec(stack[top]))
             { 
               pop();  
             }
             push(infix[i]);
           }
      }
     else if(infix[i]=='(')
      {
        top++;
        stack[top]=infix[i];
      } 
     else if(infix[i]==')')
      {
        while(stack[top]!='(')
         { 
           pop();
         }
        pop();
      }
     i++;
    }
  show();
}
