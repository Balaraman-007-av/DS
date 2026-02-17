#include<iostream>
using namespace std;
#define Max n
class Stack
{
    int top,max;
    int *array;
    public:
        Stack(int n)
        {
            top=-1;
            array = new int[n];
            max=n-1;
        }
        ~Stack()
        {
            delete[] array;
        }
        void push(int value)
        {
            if(top==max) cout<<"Stack Overflow\n";
            else array[++top]=value;
        }
        void pop()
        {
            if(top==-1) cout<<"Stack Underflow\n";
            else cout<<array[top--]<<" : "<<"Popped\n";
        }
        int peek()
        {
            if(top==-1) cout<<"Stack is Empty\n";
            else return array[top];
        }
        bool isEmpty()
        {
            return top==-1;
        }
        bool isFull()
        {
            return top==max;
        }
        int size()
        {
            return top + 1; 
        }
        void display()
        {
            if(top==-1) cout<<"Stack is Empty\n";
            else
            {
                cout<<"Element of Stack: ";
                for(int i=top;i>=0;i--)
                {
                    cout<<array[i]<<" ";
                }
                cout<<endl;
            }
        }
};
int main()
{
    int n,choice,val;
    cout<<"Enter size of the stack: ";
    cin>>n;
    Stack s(n);
    while(choice!=8)
    {
        cout<<"-----------MENU----------\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Size\n7. Display\n8. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to push:";
            cin>>val;
            s.push(val);
            break;
        
        case 2:
            s.pop();
            break;

        case 3:
            cout<<"The value at peek: "<<s.peek()<<endl;
            break;
            
        case 4:
            (s.isEmpty())? cout<<"Stack is empty\n" : cout<<"Stack is not empty\n";
            break;
            
        case 5:
            (s.isFull())? cout<<"Stack is Full\n" : cout<<"Stack is not Full\n";
            break;    

        case 6:
            cout<<"Size of the stack: "<<s.size()<<endl;
            break;
            
        case 7:
            s.display();
            break;
            
        case 8:
            cout<<"Exiting!\n";
            break;

        default:
            cout<<"Invalid Choice\n";
            break;
        }
    }
    return 0;
}