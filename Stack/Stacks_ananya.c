#include <stdio.h>
int Push (int stack[10], int top);
void display (int stack[10], int top);
int pop (int stack[10], int top);
void peek (int stack[10], int top);

int main()
{
    int stack[10];
    int top = -1;
    int choice;
    do
    {
        printf("\n Press 1: For push operation");
        printf("\n Press 2 : For pop operation");
        printf("\n Press 3 : For peek operation");
        printf("\n Press 4 : For displaying the stack");
        printf ("\n Press 0 : For exit");
        printf("\n Enter your choice here : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: top = Push(stack, top); 
                    break;
            case 2: top = pop(stack, top);
                    break;
            case 3: peek(stack, top);
                    break;
            case 4: display (stack, top);
                    break;
            case 0: printf("\n The program is ended\n"); 
                    break;        
            default : printf("\n Wrong Choice");  
                      break;                      
        }
    } while (choice != 0);
    return 0;
}
int Push (int stack[10], int top)
{
    int a;
    printf("\n Enter the number : ");
    scanf("%d", &a);
    if (top == 9)
    {
        printf("\n Overflow Condition");
    }
    else
    {
        top ++;
        stack [top] = a;
    }
    return top;
}
int pop (int stack[10], int top)
{
    if (top == -1)
    {
        printf("\n Undeflow Condition");
    }
    else
    {
        top --;
    }
    printf("\n The topmost element of the stack is deleted");
    return top;
}
void peek (int stack[10], int top)
{
    int topMost = stack[top];
    printf("The topmost element of the stack is %d", topMost);
}
void display (int stack[10], int top)
{
    printf("\n*********Printing The Stack***************\n");
    //printf("%d %d", top, stack[top]);
    for (int i = top; i >= 0; i --)
    {
        printf("\n %d", stack[i]);
    }
}