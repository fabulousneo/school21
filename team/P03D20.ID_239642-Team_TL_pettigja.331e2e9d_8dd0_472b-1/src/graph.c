#include "graph.h"

#include "rpn.h"
#include "stack.h"

int main(void) {
    char input_expression[1000] = {'\0'};
    int i = 0;
    char c = 0;

    while (i < 999 && c != '\n') {
        c = getchar();
        if (c != '\n') {
            input_expression[i] = c;
            i++;
        }
    }
    build_graph(input_expression);
    return 0;
}

void build_graph(const char *expression) {
    int result = 1;
    char graph_field[HEIGHT][WIDTH];
    char rpn_expression[1000];
    if (strlen(expression) == 0) {
        result = 0;
    }
    if (result == 1 && check_balance(expression) == 0) {
        result = 0;
    }
    if (result == 1 && to_rpn(expression, rpn_expression) == 0) {
        result = 0;
    }
    if (result == 1) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                graph_field[i][j] = '.';
            }
        }
        for (int i = 0; i < WIDTH; i++) {
            double x = i * (4 * M_PI) / (WIDTH - 1);
            int error = 0;
            double y = calculate_rpn(rpn_expression, x, &error);
            if (error == 0 && y >= -1.0 && y <= 1.0) {
                int j = (int)round((1.0 - y) * (HEIGHT - 1.0) / 2.0);
                if (j >= 0 && j < HEIGHT) {
                    graph_field[j][i] = '*';
                }
            }
        }
    }
    if (result == 0) {
        printf("n/a\n");
    } else {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", graph_field[i][j]);
            }
            printf("\n");
        }
    }
}