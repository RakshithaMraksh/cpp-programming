#include<iostream>
using namespace std;

class array
{
    private:
    int n;
    int *arr;
    int pos,val,dpos;
    public:
    void getarray()
    {
       cout<<"Enter number of elements in array:"<<endl;
       cin>>n;
       arr=new int[n+5];
       cout<<"Enter Array elements:"<<endl;
       for(int i=0;i<n;i++)
       {
        cin>>arr[i];
       }
    }
    void insertarray()
    {
        n++;
        cout<<"Enter position to insert:"<<endl;
        cin>>pos;
        cout<<"Enter value to insert at position:"<<endl;
        cin>>val;
        for(int i=n;i>pos-1;i--)
        {
            arr[i+1]=arr[i];
            arr[pos]=val;
        }
    }
    void deletearray(int dpos)
    {
        cout<<"Enter position to delete:"<<endl;
        cin>>dpos;
        for(int i=dpos;i<n;i++)
        {
            arr[i]=arr[i+1];
        }
        n--;
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            cout<<"Value at index"<<i<<"is"<<arr[i]<<endl;
        }
    }
    
};
int main()
{
    array A;
    int choice,dpos;
    cout<<"Enter choice:"<<endl;
    cin>>choice;
    cout<<"Read array elements:"<<endl;
    A.getarray();
    switch(choice)
    {
        case 1:
        cout<<"Array elements are:"<<endl;
        A.display();
        break;
        case 2:
        A.insertarray();
        A.display();
        break;
        case 3:
        A.deletearray(dpos);
        A.display();
        break;
        case 4:
        cout<<"DEFAULT"<<endl;
    }
    return 0;
}