#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {CONSTANT, ADD, SUB, MUL, DIV, FIBO} type;
    union {
        int constant;
        struct {struct Node *left, *right;} binary;
        struct {struct Node *arg;} unary;
    } u;
} Node;

Node* makeConstant(int value) {
    Node* node = malloc(sizeof(Node));
    node->type = CONSTANT;
    node->u.constant = value;
    return node;
}

Node* makeBinary(enum TypeTag type, Node* left, Node* right) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->u.binary.left = left;
    node->u.binary.right = right;
    return node;
}

Node* makeUnary(enum TypeTag type, Node* arg) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->u.unary.arg = arg;
    return node;
}

int calc(Node* node) {
    switch (node->type) {
        case CONSTANT: return node->u.constant;
        case ADD: return calc(node->u.binary.left) + calc(node->u.binary.right);
        case SUB: return calc(node->u.binary.left) - calc(node->u.binary.right);
        case MUL: return calc(node->u.binary.left) * calc(node->u.binary.right);
        case DIV: return calc(node->u.binary.left) / calc(node->u.binary.right);
        case FIBO: {
            int n = calc(node->u.unary.arg);
            int fib[n+1];
            fib[0] = 0;
            fib[1] = 1;
            for (int i = 2; i <= n; i++) {
                fib[i] = fib[i-1] + fib[i-2];
            }
            return fib[n];
        }
        default: return 0;
    }
}

int main() {
    Node* add = makeBinary(ADD, makeConstant(10), makeConstant(6));
    Node* mul = makeBinary(MUL, makeConstant(5), makeConstant(4));
    Node* sub = makeBinary(SUB, mul, add);
    Node* fibo = makeUnary(FIBO, sub);
    printf("add: %d\n", calc(add));
    printf("mul: %d\n", calc(mul));
    printf("sub: %d\n", calc(sub));
    printf("fibo: %d\n", calc(fibo));
    return 0;
}
