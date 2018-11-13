#include<bits/stdc++.h>
using namespace std;
#define MAX 6

int Stack[MAX];
int top = -1;

void push(int x);
void pop();
void display();

int main ()
{
int choice, val;
choice = -1;

while(choice !=4)
    {
cin>> choice;
switch(choice)
        {
            case 1:// cout<<”Enter the element to push”;
cin>>val;
push(val);
break;
            case 2: // cout<<”Enter the element to pop”;
pop();
break;
            case 3:// cout<<”Display the stack elements”;
display();
break;
default:
break;
        }
        cout<<"choice please"<<endl;
    }
return 0;
}
void push(int x)
{   if(top==MAX)
    cout<<"overflow "<<endl;
    else
   {
    Stack[top+1]=x;
    top++;
   }
}
void pop()
{ if(top==-1)
cout<<"underflow sir!"<<endl;
else
{cout<<"deleted element is"<<" "<<Stack[top--]<<endl;
}
}
void display()
{for(int i=top;i>-1;i--)
cout<<Stack[i]<<" ";
cout<<endl;
}

