//common elements of 2 arrays
#include<iostream>
using namespace std;
class comm_array
{
  78private:
   int *arr1,*arr2;
   int track[20]={0};
   int m,n;
  public:
   void read()
    { cout<<"Enter the size of first array"<<endl;
      cin>>m;
      arr1=new int[m];
      cout<<"Enter the elements of first array"<<endl;
      for(int i=0;i<m;i++)
       {
         cin>>arr1[i];
         if(track[arr1[i]==0)
         track[arr1[i]]++;
       }
      cout<<"Enter the size of second array"<<endl;
      cin>>n;
      arr2=new int[n];
      cout<<"Enter the elements of second array"<<endl;
      for(int i=0;i<n;i++)
       {
         cin>>arr2[i];
         if(track[arr2[i]]==1)
         track[arr2[i]]++;
       }
    }
   void comm()
    {
       for(int i=0;i<20;i++)
        {
         if(track[i]==2)
          {
            cout<<i<<endl;
          }
        }
     }
};
int main()
{
  comm_array obj;
  obj.read();
  obj.comm();
}
