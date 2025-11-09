#include "stack.h"

Stack* init_stack() {
    Stack* s_new = malloc(sizeof(Stack));
    s_new->top = NULL;
    return s_new;
}

void push(Stack* s, double data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = s->top;
    s->top = node;
}

double pop(Stack* s) {
    Node* ptr = s->top;
    s->top = s->top->next;
    double data = ptr->data;
    free(ptr);
    return data;
}

void destroy(Stack* s) {
    Node* ptr = s->top;
    while (ptr != NULL) {
        s->top = s->top->next;
        free(ptr);
        ptr = s->top;
    }
    free(s);
}

int is_empty(Stack* s) { return s->top == NULL; }

int is_digit(char c) { return c >= '0' && c <= '9'; }

int check_balance(const char* expr) {
    int balance = 0;
    int i = 0;
    int valid = 1;

    while (expr[i] != '\0' && valid) {
        if (expr[i] == '(') {
            balance = balance + 1;
        } else if (expr[i] == ')') {
            balance = balance - 1;
            if (balance < 0) valid = 0;
        }
        i++;
    }

    if (balance != 0) valid = 0;
    return valid;
}