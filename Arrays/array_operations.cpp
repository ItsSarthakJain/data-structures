//Array operations
#include<iostream>
using namespace std;
class arr_op
{
  int size;
  int *arr;
  public:
    void read();
    void output();
    void insertion();
    void deletion();
    void searching_L();
    void searching_B();
    void sorting();
};
void arr_op::read()
{
cin>>size;
arr=new int[size];
  for(int i=0;i<size;i++)
   {
     cin>>arr[i];
   }
}
void arr_op::output()
{
  for(int i=0;i<size;i++)
   {
     cout<<arr[i];
   }
  cout<<endl;
}
void arr_op::insertion()
{
  int pos,value;
  cout<<"Enter the postion and the value: "<<endl;
  cin>>pos>>value;
  for(int i=size-1;i>=pos;i--)
   {
     arr[i+1]=arr[i];
   }
     arr[pos]=value;
     size++;
  output();
}
void arr_op::deletion()
{
  int pos;
  cout<<"Enter the postion : "<<endl;
  cin>>pos;
  for(int i=pos+1;i<size;i++)
   {
     arr[i-1]=arr[i];
   }
     size--;
  output();
}
void arr_op::searching_L()
{
  int key;
  int flag=0;
  cout<<"Enter the key to be searched: "<<endl;
  cin>>key;
  for(int i=0;i<size;i++)
   {
     if(arr[i]==key)
      {
        flag=1;
        cout<<"found at location: "<<i<<endl;
        break;
      }
   }
   if(flag==0)
    {
      cout<<"Element not found"<<endl;
    }
}
void arr_op::sorting()
{ int temp=0;
  for(int p=1;p<size;p++)
   {
     for(int c=0;c<size-p;c++)
      {
        if(arr[c]>arr[c+1])
         {
           temp=arr[c];
           arr[c]=arr[c+1];
           arr[c+1]=temp;
         }
      }
   }
}
void arr_op::searching_B()
{
  int key;
  cout<<"Enter the key to be searched: "<<endl;
  cin>>key;
  int beg=0;
  int flag=0;
  int end=size-1;
  while(beg<=end)
  {
    int mid;
    mid=(beg+end)/2;
    if(arr[mid]==key)
    {
      flag=1;
      cout<<"found at loation: "<<mid<<endl;
      break;
    }
    else if(arr[mid]>key)
    {
      end=mid-1;
    }
    else
    {
      beg=mid+1;
    }
  }
  if(flag==0)
  {
    cout<<"elememt not found"<<endl;
  }
}
int main()
{
  arr_op obj;
  int option;
  int flag=0;
  do
   {
     cout<<"Press 1 for input"<<endl;
     cout<<"Press 2 for output"<<endl;
     cout<<"Press 3 for insertion"<<endl;
     cout<<"Press 4 for deletion"<<endl;
     cout<<"Press 5 searching"<<endl;
     cout<<"Press 6 for sorting the array"<<endl;
     cout<<"Press 0 for exit"<<endl;
     cin>>option;
     switch(option)
     {
       case 1:
         {
           flag=1;
           obj.read();
         }
           break;
       case 2:
         {
          if(flag==1)
           {
            obj.output();
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
            obj.insertion();
           }
          else
           {
             cout<<"Please enter the input first"<<endl;
           }           
         }
           break;
       case 4:
         {
          if(flag==1)
           {
            obj.deletion();
           }
          else
           {
             cout<<"Please enter the input first"<<endl;
           }
         }
           break;
       case 5:
        {
         if(flag=1)
          {
            char s;
            cout<<"Enter l for linear searching and b for binary searching"<<endl;
            cin>>s;
            if(s=='l')
              obj.searching_L();
            else
              obj.searching_B();
          }
         else
          {
            cout<<"Please enter the input first"<<endl;
          }
        }
           break;
       case 6:
        {
          if(flag==1)
           {
            obj.sorting();
           }
          else
           {
             cout<<"Please enter the input first"<<endl;
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
