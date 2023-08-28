#ifndef STACK_H
#define STACK_H


#define MAX_SIZE 100

// intilaizie stack to create stack
typedef struct {
    char [MAX_SIZE];
    int top;
} Stack;

/* Function init  */
void initialize(Stack *stack);

/*Function Push value  stack  */
void push(Stack *stack, char value);

/*Function Push value  stack  */
char pop(Stack *stack);

char peek(Stack *stack);


// Function take opertation
int isOperator(char ch);

int getPrecedence(char op);

//Convert the infix expression to postfix notation.
void infixToPostfix(char *infix, char *postfix);

// Evaluate postfix expression
int evaluatePostfix(const char *postfix);




#endif
