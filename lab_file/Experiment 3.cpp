#include<iostream>
using namespace std;
int main()
{
int a[20],n,i,j,ele,flag=0,temp;
int mid,min,max;
cout<<"Enter the size of array: ";
cin>>n;
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"Array is:\n";
for(i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;
for(i=0;i<n;i++)
{
    for(j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}
cout<<"\nAfter sorting the array: \n";
for(i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;
cout<<"\nEnter the element to search: ";
cin>>ele;
min=0;
max=n-1;
mid=(min+max)/2;
if(min<max)
{
    for(i=0;i<n;i++)
    {
        if(a[mid]==ele)
        {
            cout<<"Position of "<<ele<<" is: "<<mid+1;
            flag=1;
            break;
        }
        else if(a[mid]>ele)
        {
            max=mid-1;
        }
        else if(a[mid]<ele)
        {
            min=mid+1;
        }
        mid=(min+max)/2;
    }
}
if(flag==0)
    cout<<"Element not found ";
return 0;
}
