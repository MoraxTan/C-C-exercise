/*  C Program to convert infix to postfix and evaluate postfix expression  */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

void push(long int symbol);
long int pop();
void infix_to_postfix();
long int eval_post();
int priority(char symbol);
int isEmpty();
int white_space(char );

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

/* main program */
int main()
{
    long int value;
    top=-1;
    
    printf("Enter infix : ");
    gets(infix);
    
    infix_to_postfix();
    printf("Postfix : %s\n",postfix);
    
    value=eval_post();
    printf("Value of expression : %ld\n",value);

    return 0;

}/* end of main() */

/* function to convert form infix to postfix expression */
void infix_to_postfix()
{
    unsigned int i,p=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++)
    {
    	symbol=infix[i];
    	if(!white_space(symbol))
    	{
        	switch(symbol)
        	{
            	case '(':
            		push(symbol);
                	break;
            	case ')':
            		while((next=pop())!='(') /* remove '(' */
					{
            			postfix[p++] = next;
					}
                	break;
            	case '+':
            	case '-':
            	case '*':
            	case '/':
            	case '%':
            	case '^':
                	while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
					{
                		postfix[p++]=pop();
					}             
                	push(symbol);
                	break;
            	default: 
                	postfix[p++]=symbol;/* if an operand comes */
        	}
    	}
    
    }
    
    while(!isEmpty( ))
	{
        postfix[p++]=pop();
	}
	
    postfix[p]='\0'; /* end postfix with'\0' to make it a string */
    
}/* end of infix_to_postfix() */

/* this function returns the priority of the operator */
int priority(char symbol)
{
        switch(symbol)
        {
        case '(':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
                return 3;
        default :
                return 0;
        }
}/* end of priority() */

void push(long int symbol) /* this is push method */
{
    if(top>MAX)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top]=symbol;
}/* end of push() */

long int pop() /* this o is pop method */
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
}/*end of pop()*/

int isEmpty() /* check console input is empty or not */
{
    if(top==-1)
        return 1;
    else
        return 0;
}/*end of isEmpty()*/

int white_space(char symbol)
{
    if( symbol == BLANK || symbol == TAB )
        return 1;
    else
        return 0;
}/* end of white_space() */

long int eval_post()/* this function is used to evaluate a postfix expression */
{
    long int a,b,temp,result;
    unsigned int i;

    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0') push(postfix[i]-'0');
        else 
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
            	temp=b+a; 
				break;
            case '-':
                temp=b-a;
				break;
        	case '*':
                temp=b*a;
				break;
            case '/':
                temp=b/a;
				break;
            case '%':
                temp=b%a;
				break;
            case '^':
                temp=pow(b,a);
                break;
            }
        push(temp);
        }
    }
    
    result=pop();
    return result;
}/*end of eval_post */
