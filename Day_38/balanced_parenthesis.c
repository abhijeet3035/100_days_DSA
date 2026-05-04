// Day 38: Balanced Parenthesis Checker using Stack
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { if (top == -1) return '\0'; return stack[top--]; }

int isBalanced(char *exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char c = pop();
            if ((exp[i] == ')' && c != '(') ||
                (exp[i] == '}' && c != '{') ||
                (exp[i] == ']' && c != '['))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);
    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
