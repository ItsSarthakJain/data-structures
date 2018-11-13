//linked list
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
       previous=NULL;ptr=start;temp=NULL;
      while(ptr!=NULL)
       {
          temp=ptr->next;
          ptr->next=previous;
          previous=ptr;
          ptr=temp;
       }
     start=previous;
     ptr=start;
       while(ptr!=NULL)
        {
          cout<<ptr->value<<" ";
          ptr=ptr->next;
        }
    }
   void insert_beg(int num)
    {
       new_node=new node;
       new_node->value=num;
       new_node->next=start;
       start=new_node;
    }
  void insert_end(int num)
    {
       new_node=new node;
       new_node->value=num;
       new_node->next=NULL;
       save->next=new_node;
       save=new_node;
    }

   void insert_after(int given,int num)
    {   copy_==NULL;
      ptr=start;
      while(ptr!=NULL)
       {
         if(ptr->value==given)
          {
            break;
          }
         ptr=ptr->next;
       }
       new_node=new node;
       new_node->value=num;
       new_node->next=ptr->next;
       ptr->next=new_node;
    }
   void insert_before(int given,int num)
     {
       ptr=start;
       while(ptr!=NULL)
        {
          if(ptr->value==given)
           {
             break;
           }
           copy_=ptr;
           ptr=ptr->next;
        }
       if(copy_==NULL)
        {
           insert_beg(num);
        }
       else
        {
           new_node=new node;
           new_node->value=num;
           new_node->next=copy_->next;
           copy_->next=new_node;
        }
     }
    void insert_sort(int num)
     {
       ptr=start;
       while(ptr!=NULL)
        {
          if(ptr->value>num)
           {
              break;
           }
           copy_=ptr;
           ptr=ptr->next;
        }
       if(ptr==NULL)
        {
           insert_end(num);
        }
       else if(copy_==NULL)
        {
           insert_beg(num);
        }
       else
        {
           new_node=new node;
           new_node->value=num;
           new_node->next=copy_->next;
           copy_->next=new_node;
        }
     }  
   void del_beg()
    {
      temp=start;
      start=temp->next; 
      temp->next=NULL;
      delete temp;
    }  
   void del_end()
    {
       ptr=start;
       while(ptr->next->next!=NULL)
        {
          ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=NULL;
        delete temp;
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
    void del_duplicate()
     {
       ptr1=start;
       while(ptr1!=NULL)
        {
          save=ptr1;
          saved(save);
          ptr1=ptr1->next;
        }
     }
    void saved(struct node*save)
     { 
       temp=save->next;
       int c=0;
       while(temp!=NULL)
        {  /*cout<<save->value<<endl;cout<<temp->value<<endl;*/
          
          if(save->value==temp->value)
           { 
              copy_=temp->next;  
              del_pos(c);
              temp=copy_;
           }
          else
           {
             temp=temp->next;
           }
           c++;
        }
     }
}; 
int main()
{
  ll obj;
  int flag=0;
  int option,num;
  do
  {
    cout<<"Press 1 for creating the linked list(SINGLY)"<<endl;
    cout<<"Press 2 for output"<<endl;
    cout<<"Press 3 for inserting an element"<<endl;
    cout<<"Press 4 for deletion"<<endl;
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
             cout<<"Press c to insert after a number"<<endl;
             cout<<"Press d to insert before a number"<<endl;
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
             cout<<"Press e to delete duplicate elements of the list"<<endl;
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
                 case 'e':
                  {
                    obj.del_duplicate();
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

