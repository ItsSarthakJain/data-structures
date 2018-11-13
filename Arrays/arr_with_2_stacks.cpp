//2 stacks using array
#include<iostream>
using namespace std;
class stacks_2
{
  int *arr;
  int size;
  int top1,top2;
 public:
   stacks_2(int n)
    {
      size=n;
      arr= new int[size];
      top1=-1;
      top2=size;
    }
   void push1(int x)
    {
      if(top1<top2-1)
       {
        top1++;
        arr[top1]=x;
       }
      else
       {
         cout<<"Overflow"<<endl;
       }
    }
   void push2(int x)
    {
      if(top1<top2-1)
       {
        top2--;
        arr[top2]=x;
       }
      else
       {
         cout<<"Overflow"<<endl;
       }
    }
   int pop1()
    {
      if(top1>=0)
       {
        int x=arr[top1];
        top1--;
        return x;
       }
      else
       {
         cout<<"Underflow";
       }
    }
   int pop2()
    {
      if(top2<size)
       {
        int x=arr[top2];
        top2++;
        return x;
       }
      else
       {
         cout<<"Underflow";
       }
    }
};
int main()
{
  int size,option,num,popped;
  cout<<"Enter size: ";
  cin>>size;
  stacks_2 s(size);
 do
 {
  cout<<"Enter 11 to push element in stack1"<<endl;
  cout<<"Enter 12 to pop element in stack1"<<endl;
  cout<<"Enter 21 to push element in stack2"<<endl;
  cout<<"Enter 22 to pop element in stack2"<<endl;
  cin>>option;
 switch(option)
  {
    case 11:
     { cin>>num; s.push1(num); }
     break;
    case 12:
     {  popped=s.pop1(); cout<<popped<<endl; } 
    break;
   case 21:
     { cin>>num; s.push2(num); }
     break;
    case 22:
     {  popped=s.pop2(); cout<<popped<<endl; } 
    break;
  }
 }while(option!=0);
}
