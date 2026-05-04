// Day 34: Evaluate Postfix Expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

int evaluatePostfix(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isdigit(c)) {
            push(c - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push((int)pow(a, b)); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression (single digit operands, no spaces): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
