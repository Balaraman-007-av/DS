#include <stdio.h>

 #define MAX 6

int stack[MAX];
int top = -1 ;
int isfull()
 // Overflow or isfull
 {
     if(top == MAX - 1)
        return 1;
     else
        return 0;
 }
 //underflow or isempty
 int isempty()
 {
     if(top== -1)
        return 1;
     else
        return 0;
 }
 void push(int value)
 {
     if(!isfull)
     {
         top ++;
         stack [top] = value;
     }
 }
 int pop()
{
int del;
//check underflow
if(!isempty())
{

    del = stack[top];
    top --;
}
return del;
}
int peek()
{
    int p;
    if(!isempty())
    {
        p = stack [top];
    }
    return p;
}
void display()
{
    int i;
    if(!isempty())
    {

        for (i = top; i>=0;i--)
        {
          printf("%d",stack[i]);
        }

}   }
int main()
{

    push(50);
    pop(10);
    push(6);
    pop();
    display();
    printf("\n %d", peek());
    return 0;
}