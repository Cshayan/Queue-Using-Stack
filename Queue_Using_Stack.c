//Implement queue using stack
#include <stdio.h>
#include <stdlib.h>

void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();

int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;

void main()
{
    int ch;

    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeue element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
   // create();
    while (1)
    {
        printf("\nEnter choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}

//Function to create a queue
void create()
{
    top1=top2=-1;
}

//Function to push the element on to the stack1
void push1(int data)
{
    if(top1==99)
    {
        printf("\nQueue is full\n");
        return;
    }
    st1[++top1] = data;
}

//Function to pop the element from the stack1
int pop1()
{
    return(st1[top1--]);
}

//Function to push an element on to stack2
void push2(int data)
{
    st2[++top2] = data;
}

//Function to pop an element from th stack2
int pop2()
{
    int val=st2[top2--];
    return val;
}

//Function to add an element into the queue using stack
void enqueue()
{
    int data, i;

    printf("Enter data into queue");
    scanf("%d", &data);
    push1(data);                      //push data to stack1
    count++;
}

//Function to delete an element from the queue using stack
void dequeue()
{
    int i;
    if(count==0)
      {
        printf("\nQueue is empty\n");
        return;
      }
    for (i = 1;i <= count;i++)
    {
        push2(pop1());                //pop from stack1 and push them in stack2
    }

    printf("\nDeleted element is:- %d\n",pop2());   // pop the top value from stack2
    count--;
    for (i = 1;i <= count;i++)
    {
        push1(pop2());              //push the remaining elements from stack2 to stack1
    }
}

//Function to display the elements in the stack
void display()
{
    int i;
     if(top1!=-1)
     {
           for (i = 0;i <= top1;i++)
           {
              printf(" %d ", st1[i]);
           }
     }
     else
     {
        printf("\nQueue is empty\n");
     }
}
