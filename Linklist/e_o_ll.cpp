//even odd elements in a linked list
#include<iostream>
using namespace std;
class e_o_ll
{ 
  private:
   struct node
   {
     int value;
     struct node*next;
   };
  struct node*start;
  struct node*new_node;
  struct node*ptr;
  struct node*save;
  public:
   e_o_ll()
    {
      start=NULL;
    }
   void create_ll_b()
    {
     start=NULL;
     int num;
      cin>>num;
      while(num!=-1)
       {
         new_node=new node;
         new_node->value=num;
         new_node->next=start;
         start=new_node;
         cin>>num;
       }
    }
   void create_ll_e()
    {
      start=NULL;
      int num;
      cin>>num;
      while(num!=-1)
       {
         if(start==NULL)
          {
            new_node=new node;
            new_node->value=num;
            new_node->next=start;
            start=new_node;
            save=new_node;
          }
         else
          {
            new_node=new node;
            new_node->value=num;
            new_node->next=NULL;  //new_node->next=save->next 
            save->next=new_node;
            save=new_node; 
          }
         cin>>num;
        }
    }
   void show()
    {
       ptr=start;
       while(ptr!=NULL)
        {
          cout<<ptr->value<<" ";
          ptr=ptr->next;
        }
      cout<<endl;
    }
 void eo()
    {
      int temp=0;
      ptr=start;
     while(ptr!=NULL)
      {
        if(ptr->value%2==0)
         {
           cout<<ptr->value<<cout<<endl;;
         }
       ptr=ptr->next;
      }
     ptr=start;
    while(ptr!=NULL)
      {
        if(ptr->value%2!=0)
         {
           cout<<ptr->value<<cout<<endl;
         }
       ptr=ptr->next;
      }
    }
};
int main()
{
  e_o_ll obj;
  int num;
  cout<<"Press b for insertion at beginning and e for insertion at end"<<endl;
       char ch;
       cin>>ch;
       if(ch=='b')
        {
          obj.create_ll_b();
        }
       else if(ch=='e')
        {
          obj.create_ll_e();
        }
       else
        {
          cout<<"Enter valid option";
        }
        obj.eo();
       // obj.show();
}
