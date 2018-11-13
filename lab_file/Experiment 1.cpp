#include<iostream>
using namespace std;
int main()
{
int a[20],n,i,m,pos,ele,ch,flag=0;
cout<<"Enter the size of array: ";
cin>>n;
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"\nEnter choice:\n1 for insertion\n2 for deletion\n3 for searching\n4 for display\n";
cin>>ch;
while(ch!=0)
{
    switch(ch)
    {
    case 1:
        cout<<"Enter the position and element you want to insert\n";
        cin>>pos>>ele;
        m=n-pos-1;
        for(i=n;i>=m;i--)
        {
            a[i+1]=a[i];
        }
        a[pos]=ele;
        n=n+1;
        break;
    case 2:
        cout<<"Enter the position of element you want to delete\n";
        cin>>pos;
        for(i=pos;i<n;i++)
        {
            a[i]=a[i+1];
        }
        n=n-1;
        break;
    case 3:
        flag=0;
        cout<<"\nEnter the element to search: ";
        cin>>ele;
        for(i=0;i<n;i++)
        {
            if(a[i]==ele)
            {
                cout<<"\nPosition is: "<<i+1;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\nElement not found";
        break;
    case 4:
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        break;
    }
    cout<<"\nEnter choice again: ";
    cin>>ch;
}
}

