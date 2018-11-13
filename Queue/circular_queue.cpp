//CIRCULAR QUEUE
#include<iostream>
using namespace std;
class cqueue
{
  private: 
    int *arr;
    int front,rear;
    int size;
  public:
    cqueue()
    {
     cout<<"Enter the size of Queue"<<endl;
      cin>>size;
      front=-1;
       rear=-1;
      arr=new int[size];
    }
    void enqueue(int en)
    {
      if((front==0&&rear==size-1)||(rear==front-1))
       {
          cout<<"Queue is Full"<<endl;
       }
      else if(front==-1) 
       {
          rear++;
          front++;
          arr[rear]=en;
       }
     else if(rear==size-1&&front!=0)
       {
         rear=0;
         arr[rear]=en;
       }
    else
      {
        rear++;
        arr[rear]=en;
      }
    }
  void dequeue()
    {
      if(front==-1&&rear==-1)
        {
          cout<<"Queue is Empty"<<endl;
        }
      cout<<arr[front]<<" ";
      arr[front] = -1;
        if(front==rear)
         {
           front=-1;
           rear=-1;
         }
        else if(front==size-1)
         {
           front=0;
         }
        else
         {
           front++;
         }  
    }
  void IsFull()
   {
     if((front==0&&rear==size-1)||(rear==(front-1)))
        {
           cout<<"Queue is Full";
        }
     else
        {
          cout<<"Not Full";
        }
   }
  void IsEmpty()
   {
    if(front==-1&&rear==-1)
     {
       cout<<"Queue is Empty";
     }
    else
     {
       cout<<"Queue is not Empty";
     }
   }
 };  
int main()
{
  cqueue obj;
  int option,en;
  do
 {
  cout<<"Press 1 for creating queue"<<endl;
  cout<<"Press 2 for  printing the queue"<<endl;
  cout<<"Press 3 for  checking if the queue is full"<<endl;
  cout<<"Press 4 for  checking if the queue is empty"<<endl;
  cin>>option;
  switch(option)
  {
    case 1:
     {cin>>en;  obj.enqueue(en); }
     break;
    case 2:
     {  obj.dequeue();  } 
    break;
    case 3:
     { obj.IsFull(); }
     break;
    case 4:
     { obj.IsEmpty(); }
    break;
  }
 }while(option!=0);
}
  
