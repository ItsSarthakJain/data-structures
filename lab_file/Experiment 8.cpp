#include<iostream>
using namespace std;
void insertionsort(int a[],int n)
{
    int i,j,k,temp,m;
    for(i=0;i<n;i++)
    {
        m=a[i];
        j=i;
        while(a[j-1]>m && j>0)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=m;
    }
}

int main()
{
    int i,a[20],n;
    cout<<"Enter no of elements in an array: ";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    insertionsort(a,n);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    int item;
    cout<<"\nEnter ITEM to be inserted : ";
     cin>>item;
     i = n-1;
     while(item<a[i] && i>=0)
     {
           a[i+1] = a[i];
           i--;
     }
     a[i+1] = item;
     n++;
     cout<<"\nAfter insertion array is :\n";
      for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

}
