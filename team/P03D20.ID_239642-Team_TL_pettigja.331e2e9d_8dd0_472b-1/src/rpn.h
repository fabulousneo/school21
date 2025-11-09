#ifndef RPN_H
#define RPN_H

int to_rpn(const char *expr, char *output);
double calculate_rpn(const char *rpn, double x, int *error);

#endif