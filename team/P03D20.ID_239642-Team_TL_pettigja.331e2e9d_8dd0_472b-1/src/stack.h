#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    double data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack *init_stack();
double pop(Stack *s);
int is_digit(char c);
int is_empty(Stack *s);
void destroy(Stack *s);
void print_stack(Stack *s);
void push(Stack *s, double value);
int check_balance(const char *expr);
#endif