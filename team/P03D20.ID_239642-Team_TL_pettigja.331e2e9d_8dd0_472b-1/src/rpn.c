#include "rpn.h"

#include "stack.h"

typedef struct {
    int expect_operand;
    int count_operations;
    int count_operand;
    int is_unary;
    int count_funcs;
    int count_open_brackets;
} Flags;

int precedence(char op) {
    int result = 0;
    if (op == '+' || op == '-') {
        result = 1;
    } else if (op == '*' || op == '/') {
        result = 2;
    } else if (op == '~') {
        result = 3;
    }
    return result;
}

int do_unary(char oper, Stack *op_stack, int *i, Flags *flags) {
    int success = 1;
    if (flags->is_unary) {
        success = 0;
    } else {
        flags->is_unary = 1;
    }
    if (oper == '+') {
        success = 0;
    }
    if (oper == '-') {
        push(op_stack, '~');
    }
    (*i)++;
    return success;
}

int do_digits(const char *expr, char *output, int *i, int *out_index, Flags *flags) {
    int success = 1;
    flags->expect_operand = 0;
    flags->is_unary = 0;
    flags->count_operand++;
    if (expr[*i] == 'x' && (expr[(*i) + 1] == 'x' || is_digit(expr[(*i) + 1]) || expr[(*i) + 1] == '.')) {
        success = 0;
    }
    if (is_digit(expr[*i]) && (expr[(*i) + 1] == 'x')) {
        success = 0;
    }
    if (expr[0] == '.') {
        success = 0;
    } else if (expr[*i] == '.' && (!is_digit(expr[(*i) - 1]) || !is_digit(expr[(*i) + 1]))) {
        success = 0;
    }
    while (is_digit(expr[*i]) || expr[*i] == 'x' || expr[*i] == '.') {
        output[(*out_index)++] = expr[(*i)++];
    }
    output[(*out_index)++] = ' ';
    return success;
}

int do_func(const char *expr, Stack *op_stack, int *i, Flags *flags) {
    char *funcs[] = {"sin", "cos", "tan", "ctg", "sqrt", "ln"};
    char func_chars[] = {'s', 'c', 't', 'g', 'q', 'l'};
    flags->expect_operand = 1;
    flags->is_unary = 0;
    (flags->count_funcs)++;
    int success = 0;
    for (int j = 0; j < 6; j++) {
        if (strncmp(&(expr[*i]), funcs[j], strlen(funcs[j])) == 0) {
            push(op_stack, func_chars[j]);
            (*i) += strlen(funcs[j]);
            success = 1;
        }
    }
    return success;
}

int do_open_bracket(const char *expr, Stack *op_stack, int *i, Flags *flags) {
    flags->expect_operand = 1;
    flags->is_unary = 0;
    flags->count_open_brackets++;
    int success = 1;
    if (expr[(*i) + 1] == ')') {
        success = 0;
    }
    push(op_stack, '(');
    (*i)++;
    return success;
}

int do_close_bracket(Stack *op_stack, int *i, char *output, int *output_index, Flags *flags) {
    int success = 1;
    flags->expect_operand = 0;
    flags->is_unary = 0;
    while (!is_empty(op_stack) && (char)op_stack->top->data != '(') {
        output[(*output_index)++] = (char)pop(op_stack);
        output[(*output_index)++] = ' ';
    }
    if (is_empty(op_stack)) {
        success = 0;
    } else {
        pop(op_stack);
        if (!is_empty(op_stack)) {
            char top_char = (char)op_stack->top->data;
            if (top_char == 's' || top_char == 'c' || top_char == 't' || top_char == 'g' || top_char == 'q' ||
                top_char == 'l') {
                output[(*output_index)++] = (char)pop(op_stack);
                output[(*output_index)++] = ' ';
            }
        }
    }
    (*i)++;
    return success;
}

int do_oper(Stack *op_stack, int *i, char *output, int *output_index, char oper, Flags *flags) {
    flags->expect_operand = 1;
    flags->is_unary = 0;
    flags->count_operations++;
    while (!is_empty(op_stack) && (char)op_stack->top->data != '(' &&
           precedence((char)op_stack->top->data) >= precedence(oper)) {
        output[(*output_index)++] = (char)pop(op_stack);
        output[(*output_index)++] = ' ';
    }
    push(op_stack, oper);
    (*i)++;
    return 1;
}

int check_symbols(const char *expr, char *output, int *output_index, Stack *op_stack) {
    int i = 0;
    int success = 1;
    Flags flags = {.expect_operand = 1,
                   .count_operations = 0,
                   .count_operand = 0,
                   .is_unary = 0,
                   .count_funcs = 0,
                   .count_open_brackets = 0};
    while (expr[i] != '\0' && success) {
        if (expr[i] == ' ') {
            i++;
            success = 0;
        } else if ((expr[i] == '+' || expr[i] == '-') && flags.expect_operand) {
            success = do_unary(expr[i], op_stack, &i, &flags);
        } else if (is_digit(expr[i]) || expr[i] == 'x' || expr[i] == '.') {
            success = do_digits(expr, output, &i, output_index, &flags);
        } else if (expr[i] == 's' || expr[i] == 'c' || expr[i] == 't' || expr[i] == 'l') {
            success = do_func(expr, op_stack, &i, &flags);
        } else if (expr[i] == '(') {
            success = do_open_bracket(expr, op_stack, &i, &flags);
        } else if (expr[i] == ')') {
            success = do_close_bracket(op_stack, &i, output, output_index, &flags);
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            success = do_oper(op_stack, &i, output, output_index, expr[i], &flags);
        } else {
            success = 0;
        }
    }
    if (flags.count_operand - 1 != flags.count_operations || flags.count_funcs > flags.count_open_brackets) {
        success = 0;
    }

    return success;
}

int to_rpn(const char *expr, char *output) {
    Stack *op_stack = init_stack();

    int output_index = 0;

    int success = check_symbols(expr, output, &output_index, op_stack);

    while (!is_empty(op_stack) && success) {
        if ((char)op_stack->top->data == '(') {
            success = 0;
        } else {
            output[output_index++] = (char)pop(op_stack);
            output[output_index++] = ' ';
        }
    }

    if (success) {
        output[output_index] = '\0';
    }
    destroy(op_stack);
    return success;
}

int push_numb(const char *rpn, int *i, Stack *stack) {
    char *end_numb;
    double num = strtod(&rpn[*i], &end_numb);
    push(stack, num);
    *i = end_numb - rpn;
    return 1;
}

int push_func(const char *rpn, int *i, Stack *stack) {
    double a = pop(stack);
    int success = 1;
    if (rpn[*i] == 's')
        push(stack, sin(a));
    else if (rpn[*i] == 'c')
        push(stack, cos(a));
    else if (rpn[*i] == 't')
        push(stack, tan(a));
    else if (rpn[*i] == 'g') {
        double tan_val = tan(a);
        if (fabs(tan_val) < 1e-10)
            success = 0;
        else
            push(stack, 1.0 / tan_val);
    } else if (rpn[*i] == 'q') {
        if (a < 0)
            success = 0;
        else
            push(stack, sqrt(a));
    } else if (rpn[*i] == 'l') {
        if (a <= 0)
            success = 0;
        else
            push(stack, log(a));
    } else if (rpn[*i] == '~')
        push(stack, -a);

    (*i)++;
    return success;
}

int push_oper(const char *rpn, int *i, Stack *stack) {
    double b = pop(stack);
    double a = pop(stack);
    int success = 1;
    if (rpn[*i] == '+')
        push(stack, a + b);
    else if (rpn[*i] == '-')
        push(stack, a - b);
    else if (rpn[*i] == '*')
        push(stack, a * b);
    else if (rpn[*i] == '/') {
        if (fabs(b) < 1e-10)
            success = 0;
        else
            push(stack, a / b);
    }
    (*i)++;
    return success;
}

int calculation(const char *rpn, Stack *stack, double x) {
    int success = 1;
    int i = 0;
    while (rpn[i] != '\0' && success) {
        if (rpn[i] == ' ') {
            i++;
        } else if (is_digit(rpn[i]) || rpn[i] == '.') {
            success = push_numb(rpn, &i, stack);
        } else if (rpn[i] == 'x') {
            push(stack, x);
            i++;
        } else if (rpn[i] == 's' || rpn[i] == 'c' || rpn[i] == 't' || rpn[i] == 'g' || rpn[i] == 'q' ||
                   rpn[i] == 'l' || rpn[i] == '~') {
            success = push_func(rpn, &i, stack);
        } else if (rpn[i] == '+' || rpn[i] == '-' || rpn[i] == '*' || rpn[i] == '/') {
            success = push_oper(rpn, &i, stack);
        } else {
            success = 0;
        }
    }
    return success;
}

double calculate_rpn(const char *rpn, double x, int *error) {
    Stack *stack = init_stack();
    double result = 0.0;
    int success = calculation(rpn, stack, x);

    if (success) {
        if (is_empty(stack)) {
            success = 0;
        } else {
            result = pop(stack);
            if (!is_empty(stack)) success = 0;
        }
    }
    destroy(stack);
    if (!success) {
        result = 0.0;
        *error = 1;
    }
    return result;
}