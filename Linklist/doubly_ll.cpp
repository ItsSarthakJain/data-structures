//doubly linked list
#include<iostream>
using namespace std;
class dll
{
  private:
   struct node
    {
      int value;
      struct node*previous;
      struct node*next;
    };
   struct node*start;
   struct node*tail;
   struct node*new_node;
   struct node*ptr;
  public:
    dll()
     {
       start=NULL;
     }
    void create_dll_b()
     { start=NULL;
       int num;
       cin>>num;
      while(num!=-1)
       {
         if(start==NULL)
          {
            new_node=new node;
            new_node->value=num;
            new_node->previous=NULL;
            new_node->next=NULL;
            start=new_node;
            tail=new_node;
          }
         else
          {
            new_node=new node;
            new_node->value=num;
            new_node->previous=NULL;
            new_node->next=start;
            start=new_node;
          }
        cin>>num;
        }
      }
    void create_dll_e()
     { start=NULL;
       int num;
       cin>>num;
      while(num!=-1)
       {
         if(start==NULL)
          {
            new_node=new node;
            new_node->value=num;
            new_node->previous=NULL;
            new_node->next=NULL;
            start=new_node;
            tail=new_node;
          }
         else
          {
            new_node=new node;
            new_node->value=num;
            new_node->previous=tail;
            new_node->next=NULL;
            tail->next=new_node;
            tail=new_node;
          }
         cin>>num;
       }
     }
    void insert_beg(int num)
     {
       new_node=new node;
       new_node->value=num;
       new_node->previous=NULL;
       new_node->next=start;
       start=new_node;
     }
    void insert_end(int num)
     {
       new_node=new node;
       new_node->value=num;
       new_node->previous=tail;
       new_node->next=NULL;
       tail->next=new_node;
       tail=new_node;
     }
    void insert_after(int given,int num)
    { ptr=start;
      while(ptr!=NULL)
      {
        if(ptr->value==given)
         {
           break;
         }
        ptr=ptr->next;
      }
       if(ptr==NULL)
        {
          cout<<"Element not found";
        }
       else if(ptr->next==NULL)
        {
           insert_end(num);
        }
       else
        {
           new_node=new node;
           new_node->value=num;
           new_node->previous=ptr;
           new_node->next=ptr->next;
           ptr->next->previous=new_node;
           ptr->next=new_node;
        }
    }
  void insert_before(int given,int num)
    { ptr=start;
      while(ptr!=NULL)
      {
        if(ptr->value==given)
         {
           break;
         }
        ptr=ptr->next;
      }
       if(ptr==NULL)
        {
          cout<<"Element not found";
        }
       else if(ptr->previous==NULL)
        {
           insert_beg(num);
        }
       else
        {
           new_node=new node;
           new_node->value=num;
           new_node->previous=ptr->previous;
           new_node->next=ptr;
           ptr->previous->next=new_node;
           ptr->previous=new_node;
        }
    }
  void insert_sort(int num)
   {
     ptr=start;
     while(ptr!=NULL)
     {
       if(ptr->value>=num)
        {
          break;
        }
       ptr=ptr->next;
     }
     if(ptr==NULL)
      {
        insert_end(num);
      }
     else if(ptr->previous==NULL)
      {
         insert_beg(num);
      }
     else
      {
           new_node=new node;
           new_node->value=num;
           new_node->previous=ptr->previous;
           new_node->next=ptr;
           ptr->previous->next=new_node;
           ptr->previous=new_node;
      }
    }
   void del_beg()
    {
         if(start->next==NULL)
          {
            start=NULL;
          }
         else
          {
             ptr=start;
             start=ptr->next;
             ptr->next=NULL;
             start->previous=NULL;
          }
        delete ptr;
    }
  void del_end()
    {
        ptr=start;
       if(tail->previous!=NULL)
        {
          while(ptr->next!=NULL)
           {
             ptr=ptr->next;
           }
          ptr->previous->next=NULL;
          ptr->previous=NULL;
        }
       else
        {
           start=NULL;
        }   
          delete ptr;
    }
  void del_given(int num)
    {
      ptr=start;
      while(ptr!=NULL)
       {
          if(ptr->value==num)
           {
             break;
           }
          ptr=ptr->next;
       }
       if(ptr==NULL)
        {
          cout<<"Element not found";
        }
       else if(ptr->next==NULL)
        {
           del_end();
        }
       else if(ptr->previous==NULL)
        {
           del_beg();
        }
       else
        {
          ptr->previous->next=ptr->next;
          ptr->next->previous=ptr->previous;
          ptr->previous=NULL;
          ptr->next=NULL;
         delete ptr;
        }
     }
   void del_pos(int pos)
    {
      int c=0;
      ptr=start;
     while(ptr!=NULL)
      {
        c=c+1;
       if(c==pos)
        {
          break;
        } 
       ptr=ptr->next;
      }
       if(ptr->previous==NULL)
        {
          del_beg();
        }
       else if(ptr==NULL)
        {
          del_end();
        }
       else
        {
            ptr->previous->next=ptr->next;
            ptr->next->previous=ptr->previous;
             ptr->next=NULL;
             ptr->previous=NULL;
             delete ptr;
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
};
int main()
{
  dll obj;
  int flag=0;
  int option,num;
  do
  {
    cout<<"Press 1 for creating the linked list(doubly)"<<endl;
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
          obj.create_dll_b();
        }
       else if(ch=='e')
        {
          obj.create_dll_e();
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
             cout<<"Press c to insert after"<<endl;
             cout<<"Press d to insert before"<<endl;
             cout<<"Press e to insert in a sorted list"<<endl;
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
                 case 'c':
                  {
                    cout<<"Enter the loaction after"<<endl;
                    cin>>given;
                    obj.insert_after(given,num);
                  }
                   break; 
                 case 'd':
                  {
                    cout<<"Enter the loaction before"<<endl;
                    cin>>given;
                    obj.insert_before(given,num);
                  }
                   break; 
                 case 'e':
                  {
                    obj.insert_sort(num);
                  }
                  break;
                 default:
                   cout<<"not a valid option"<<endl;
               }
            }
           else
            {
              cout<<"Enter the input first"<<endl;
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
