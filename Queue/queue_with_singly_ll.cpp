#include<iostream>
using namespace std;

class q_ll
{
    struct node
    {
        int value;
        struct node*  next;
    };
    struct node* front;
    struct node* new_node;
    struct node* ptr;
    struct node* rear;
    struct node* temp;
    struct node* copy_;
    int count;
public:
    q_ll()
    {
        front=NULL;
        count = 0;
    }
    void enqueue(int num)
    {
        if(front==NULL)
        {
            new_node=new node;
            new_node->value=num;
            new_node->next=front;
            front=new_node;
            rear=new_node;
            count++;
        }
        else
        {
            new_node=new node;
            new_node->value=num;
            new_node->next=NULL;
            rear->next=new_node;
            rear=new_node;
            count++;
        }
    }
    void dequeue()
    {
        if(front!=rear)

        {
            cout<<front->value<<endl;
            temp=front;
            front=temp->next;
            temp->next=NULL;
            delete temp;
        }
        else if(front==NULL)
        {
            cout<<endl<<"UNDERFLOW"<<endl;
        }
        else
        {
            temp=front;
            cout<<front->value<<endl;
            delete temp;
            front=NULL;
            rear=NULL;
        }
    }
    void show()
    {
        cout<<endl<<endl;
        if(front == NULL)
              cout << "UNDERFLOW" << endl;
        while(front!=NULL)
        {
            dequeue();
        }
        cout << endl;
    }
};

int main()
{
    int n,num,given;
    char a;
    q_ll obj1;
    int created=0;
   do
    {
     cout<<"Press 1 for insertion of element into queue"<<endl;
     cout<<"Press 2 to display the linked list"<<endl;
     cout<<"Press 3 to delete an element"<<endl;
     cout<<"Enter -1 for termination of program"<<endl;
     cin>>n;
        switch (n)
        {
            case 1:
            {
                cin >> num;
                obj1.enqueue(num);
                created = 1;
                break;
            }
            case 2:
             {
                if(created)
                    obj1.show();
                else
                    cout << "UNDERFLOW" << endl;
                break;
             }
            case 3:
             {
                obj1.dequeue();
                break;
             }
            default:
            {
                cout << "invalid input "<< endl;
             }
        }
    }while(n!=-1);
    return 0;
}
