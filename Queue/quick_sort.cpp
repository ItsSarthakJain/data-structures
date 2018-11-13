//Quick sort
#include<iostream>
using namespace std;
class Quick_sort
{
  private:
   int *arr,size,j,p,i,q,r;
  public:
   Quick_sort()
    {
      cin>>size;
      arr=new int [size];
    }
   void read()
    {
      for(int i=0;i<size;i++)
       {
          cin>>arr[i];
       }
       p=0;
       r=size-1;
      QS(arr,p,r);
    }
   int partition_algo(int *arr,int p,int r)
    {
      int temp;
      int pivot=arr[r];
      j=p-1;
      for(int i=p;i<r;i++)
       {
         if(arr[i]<=pivot)
          {
            j++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
          }
      }
          temp=arr[j+1];
          arr[j+1]=arr[r];
          arr[r]=temp;
     return j+1;
    }
    void QS(int *arr,int p,int r)
     {
        if(p<r)
         {
           q=partition_algo(arr,p,r);
           QS(arr,p,q-1);
           QS(arr,q+1,r);
         }
     }
    void display()
     {
        for(int i=0;i<size;i++)
         {
           cout<<arr[i]<<" ";
         }
     }
};
int main()
{
  Quick_sort obj;
  obj.read();
  obj.display();
}
