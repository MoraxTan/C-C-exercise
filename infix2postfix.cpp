#include <stdio.h>
#include <stdlib.h>
 
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
 
typedef char ElemType;
typedef struct {
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;
 
InitStack(sqStack *s) {
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s->base )
        exit(0);
 
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}
 
Push(sqStack *s, ElemType e) {
    // Stack is full,continue adding memory it.
    if( s->top - s->base >= s->stackSize ) {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
            exit(0);
 
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
 
    *(s->top) = e;      // There hava put a data here.
    s->top++;
}
 
Pop(sqStack *s, ElemType *e) {
    if( s->top == s->base )
        return;
 
    *e = *--(s->top);   // The top element pop up from stack.And edited the pointer.
}
 
int StackLen(sqStack s) {
    return (s.top - s.base);
}
 
int main() {
    sqStack s;
    char c, e;
 
    InitStack( &s );
 
    printf("Enter the Infix Expression,and end with symbol'#':\n");
    scanf("%c", &c);
 
    while( c != '#' ) {
        while( c >= '0' && c <= '9' ) {
            printf("%c", c);
            scanf("%c", &c);
            if( c < '0' || c > '9' ) {
                printf(" ");
            }
        }
 
        if( ')' == c ) {
            Pop(&s, &e);
            while( '(' != e ) {
                printf("%c ", e);
                Pop(&s, &e);
            }
        }
        else if( '+'==c || '-'==c ) {
            if( !StackLen(s) ) {
                Push(&s, c);
            }
            else {
                do {
                    Pop(&s, &e);
                    if( '(' == e ) {
                        Push(&s, e);
                    }
                    else {
                        printf("%c ", e);
                    }
                }while( StackLen(s) && '('!=e );
                Push(&s, c);
            }
        }
        else if( '*'==c || '/'==c || '('==c ) {
            Push(&s, c);
        }
        else if( '#'== c ) {
            break;
        }
        else {
            printf("\nError!Please enter the correct expression.\n");
            return -1;
        }
        scanf("%c", &c);
    }
 
    while( StackLen(s) ) {
        Pop(&s, &e);
        printf("%c ", e);
    }
    return 0;
}
