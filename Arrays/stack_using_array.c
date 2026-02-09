#include<stdio.h>
#define CAPACITY 100
int stack[CAPACITY];
int SP_TOP= -1;
void push(int value)
{
    if(SP_TOP+1<CAPACITY)
    {
        SP_TOP++;
        stack[SP_TOP]=value;
        printf("Pushed Element: %d\n",value);
    }
    else
    {
        printf("The stack is full\n");
    }
}
void pop()
{
    if(SP_TOP>=0)
    {
        printf("Popped Element: %d\n",stack[SP_TOP]);
        SP_TOP--;
    }
    else printf("Empty Stack!");
}

int main()
{

}
