//implementing stack using linked list
#include<iostream>
using namespace std;
class stack_ll
{
  private:
    struct node
     {
       int value;
       struct node*next;
     };
  struct node*top;
  struct node*new_node;
  struct node*ptr;
  struct node*save;
  struct node*ptr1;
  struct node*temp;
  struct node*topp;
  public:
   stack_ll()
    {
      top=NULL;
    }
   void push(int num)
    {
     /*top=NULL;
     int num;
      cin>>num;
      while(num!=-1)
       {
         new_node=new node;
         new_node->value=num;
         new_node->next=top;
         top=new_node;
         cin>>num;
       }*/
     
      new_node=new node;
      new_node->value=num;
      new_node->next=top;
      top=new_node;
      topp=new_node;
    }
   void pop()
    {
      if(top==NULL)
       {
         cout<<"Underflow";
       }
      else
       {
       
        cout<<top->value;
       // temp=top;
        top=top->next; 
       // temp->next=NULL;
        //delete temp;
       }
   }
  void reverse()
   { cout<<"1"<<endl;
   // cout<<topp->value;
     ptr=save=topp;
     ptr=ptr->next;
     save->next=NULL;
     while(ptr!=NULL)
      {
       ptr1=ptr->next;
       ptr->next=save;
       save=ptr;
       ptr=ptr1;
      }
    topp=save;
    ptr=topp;
    while(ptr!=NULL)
    {
     cout<<ptr->value;
     ptr=ptr->next;
    }
   }
};
int main()
{
  stack_ll obj;
  int option,num;
 do
 {
cout<<"\nEnter 1 to push element\nEnter 2 to pop element";
  cin>>option;
 switch(option)
  {
    case 1:
     { cin>>num; obj.push(num); }
     break;
    case 2:
     {  obj.pop();  } 
    break;
  }
 }while(option!=0);
  obj.reverse();
}
