//stack
#include<iostream>
#define size 5
using namespace std;
class stack
{
 private:
  int *arr;
  int top;
 public:
  stack()
  { top=-1;
    arr=new int[size];
  }
  void push(int num)
   { 
     if(top>=size-1)
      { 
         cout<<"Overflow"<<endl; 
      }
     else
      {
         top++;
         arr[top]=num;
      }
    }
   int pop()
    {
      if(top<0)
	cout<<"Underflow";  
      else
      {       
         return arr[top--];
      }
    }
   void peek()
    {
     if(top<0)
	{  cout<<"No element in the stack"; }
     else
       {  cout<<arr[top];cout<<top; }
    }
};
int main()
{
  stack obj1,obj2;
  int option,r,num,p;
 do
 {

   cout<<"\nEnter 1 to push element\nEnter 2 to pop element\nEnter 3 to print peek element";
  cin>>option;
 switch(option)
  {
    case 1:
     {  cin>>num;obj1.push(num); }
     break;
    case 2:
     {  r=obj1.pop(); obj2.push(r); cout<<r<<" "<<p<<endl; } 
    break;
    case 3:
     {  p=obj2.pop();cout<<p<<endl;obj1.peek(); }
    break;
  }
 }while(option!=0);
}
