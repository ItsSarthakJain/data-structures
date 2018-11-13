//array rotation
#include<iostream>
using namespace std;
class arr_rotate
{
  private:
    int *arr,*arr1;
    int size;
  public:
    void read()
     {
       cout<<"Enter the size of array"<<endl;
       cin>>size;
       arr=new int[size];
       arr1=new int[size];
       cout<<"Enter the array elements"<<endl;
       for(int i=0;i<size;i++)
        {
          cin>>arr[i];
        }
     }
    void rotate()
     {
       int d,j=0;
       cout<<"Enter the number of rotations"<<endl;
       cin>>d;
       cout<<"Array after rotations"<<endl;
       for(int i=d;i<size;i++)
        {
          arr1[j]=arr[i];
          j++;
        }
       for(int i=0;i<d;i++)
        {
          arr1[j]=arr[i];
          j++;
        }
       for(int i=0;i<size;i++)
        {
           cout<<arr1[i]<<" ";
        }
     }
};
int main()
{
  arr_rotate obj;
  obj.read();
  obj.rotate();
}
