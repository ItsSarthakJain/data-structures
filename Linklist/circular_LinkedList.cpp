#include<iostream>
using namespace std;
class ll
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
  struct node*copy_;
  struct node*temp;
  struct node*previous;
  struct node*ptr1;
  public:
   ll()
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
        if(start==NULL)
         {
         new_node=new node;
         new_node->value=num;
         start=new_node;
         new_node->next=start;
         save=new_node;
         }
         else
         {
         new_node=new node;
         new_node->value=num;
         new_node->next=start;
         start=new_node;
         }
        cin>>num;
       }
       save->next=start;
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
        save->next=start;
    }
 void insert_beg(int num)
    {
       new_node=new node;
       new_node->value=num;
       new_node->next=start;
       start=new_node;
       save->next=start;
    }
  void insert_end(int num)
    {
       new_node=new node;
       new_node->value=num;
       new_node->next=start;
       save->next=new_node;
       save=new_node;
    }
  void del_beg()
    {  
       temp=start;
       ptr=start;
       if(start==NULL)
        {       
          cout<<"Underflow"<<endl;
        }
       else
        {       
           while(ptr->next!=save->next)
            {
              ptr=ptr->next;
            }
            ptr->next=temp->next;
            start=ptr->next;
           delete temp;
        }
    }
  void del_end()
    {
       previous=start;
       ptr=start;
       while(ptr->next!=start)
        {
          previous=ptr;
          ptr=ptr->next;
        }
       previous->next=start;
       delete ptr;
     }
    void del_given(int num)
    {
      ptr=start;
      previous=NULL;
     while(ptr!=NULL)
      {
       if(ptr->value==num)
        {
          break;
        }
       previous=ptr; 
       ptr=ptr->next;
      }
       if(previous==NULL)
        {
          del_beg();
        }
       else if(ptr==NULL)
        {
          cout<<"Doesn't exist";
        }
       else
        {
            previous->next=ptr->next;
             ptr->next=NULL;
             delete ptr;
         }
     }
    void del_pos(int pos)
    {
      int c=0;
      ptr=start;
      previous=NULL;
     while(ptr!=NULL)
      {
        c=c+1;
       if(c==pos)
        {
          break;
        }
       previous=ptr; 
       ptr=ptr->next;
      }
       if(previous==NULL)
        {
          del_beg();
        }
       else if(ptr==NULL)
        {
          cout<<"Doesn't exist";
        }
       else
        {
            previous->next=ptr->next;
             ptr->next=NULL;
             delete ptr;
         }
     }
  void show()
    {
	ptr = start;
       do
        {
          if(ptr->next==start)
           {
             cout<<ptr->value << " ";
             break;
           }
          cout << ptr->value << " ";
          ptr=ptr->next;
        }while(ptr != start);
        ptr = ptr-> next;
        cout << ptr -> value << endl;
     // cout<<endl;
	//cout << save->value << save->next->value ;
    }
};
int main()
{
  ll obj;
  int num,flag=0;
  int option;
  do
  {
    cout<<"Press 1 for creating the linked list(circular)"<<endl;
    cout<<"Press 2 for output"<<endl;
    cout<<"Press 3 for inserting an element"<<endl;
    cout<<"Press 4 for deleting an element"<<endl;
    cin>>option;
    switch(option)
    {
      case 1:
      {
       flag=1;
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
       }
         break;
      case 2:
       {
         if(flag==1)
          {
            obj.show();
          }
         else
          {
            cout<<"Please enter the input first"<<endl;
          }
       }
         break;
      case 3:
       {
          if(flag==1)
           {
             char ch;
             int given;
             cout<<"Enter the number"<<endl;
             cin>>num;
             cout<<"Press a to insert at beginning"<<endl;
             cout<<"Press b to insert at end"<<endl;
             cin>>ch;
             switch(ch)
              {
                case 'a':
                  {  
                    obj.insert_beg(num);
                  }
                   break;
                 case 'b':
                  {
                    obj.insert_end(num);
                  }
                   break;
                default:
                  {  cout<<"not a valid option"<<endl;  }
               }
           }
          else
              {
                cout<<"Please enter the input first";
              }
        }
         break;
        case 4:
         {
             if(flag==1)
           {
             char ch;
             int given;
             cout<<"Press a to delete beginning element"<<endl;
             cout<<"Press b to delete ending element"<<endl;
             cout<<"Press c to delete given number"<<endl;
             cout<<"Press d to delete number at given position"<<endl;
             cin>>ch;
             switch(ch)
              {
                case 'a':
                  {  
                    obj.del_beg();
                  }
                   break;
                 case 'b':
                  {
                    obj.del_end();
                  }
                   break;
                case 'c':
                  {
                   int num;
                   cout<<"Enter the number"<<endl;
                   cin>>num;
                   obj.del_given(num); 
                  }
                   break; 
                 case 'd':
                 {
                   int pos;
                   cout<<"Enter position"<<endl;
                   cin>>pos;
                   obj.del_pos(pos);
                  }
                   break;
                default:
                  {  cout<<"not a valid option"<<endl;  }
               }
           }
          else
              {
                cout<<"Please enter the input first";
              }
        }
         break;
               
       default:
            if(option!=0)
             {
               cout<<"invalid";
             }
     }
   }while(option!=0);
}
