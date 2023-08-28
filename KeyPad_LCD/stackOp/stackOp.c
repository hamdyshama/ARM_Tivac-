/*
 * stackOp.c
 *
 *  Created on: Aug 19, 2023
 *      Author: hanyt
 */

#include "stackOp.h"



void initialize(Stack *stack) {
    stack->top = -1; // Pointer inform element in stack
}

void push(Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;  // Push data in stack in --> Data
    } else {
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--]; // pop data in stack in --> Data    } else {
        return '\0';
    }
}


// Function take opertation
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}


/* Determine whether the precedence of operator1 is less than, equal to, or greater than
 the precedence of operator2. The function returns -1, 0 and 1, respectively.*/
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

//Convert the infix expression to postfix notation.
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initialize(&stack);

    int postfixIndex = 0;
    push(&stack, '(');
    strcat(infix, ")"); // Append ')' to infix expression

    int infixLength = strlen(infix);

    for (int i = 0; i <= infixLength; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            while (isdigit(infix[i])) {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';
            i--; // Decrement i to account for the additional increment in the loop
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (isOperator(ch)) {
            while (isOperator(stack.data[stack.top]) && getPrecedence(stack.data[stack.top]) >= getPrecedence(ch)) {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        } else if (ch == ')') {
            while (stack.data[stack.top] != '(') {
                postfix[postfixIndex++] = pop(&stack);
            }
            pop(&stack); // Pop '('
        }
    }

    postfix[postfixIndex] = '\0';
}

////////////////////////////////////////////////////////////////////

typedef struct {
    int data[MAX_SIZE];
    int top;
} _Stack;

void _initialize(_Stack *stack) {
    stack->top = -1;
}

void _push(_Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack is full!\n");
    }
}

int _pop(_Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack is empty!\n");
        return 0;
    }
}



int evaluatePostfix(const char *postfix) {
    _Stack stack;
    _initialize(&stack);

    int postfixLength = strlen(postfix);
    int result;

    for (int i = 0; i < postfixLength; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            _push(&stack, num);
        } else if (isOperator(ch)) {
            int x = _pop(&stack);
            int y = _pop(&stack);
            switch (ch) {
                case '+':
                    _push(&stack, y + x);
                    break;
                case '-':
                    _push(&stack, y - x);
                    break;
                case '*':
                    _push(&stack, y * x);
                    break;
                case '/':
                    _push(&stack, y / x);
                    break;
            }
        }
    }

    result = _pop(&stack);
    return result;
}

