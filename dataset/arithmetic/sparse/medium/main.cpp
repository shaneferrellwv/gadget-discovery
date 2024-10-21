#include <stdio.h>

int add_mod(int a, int b) {
    return (a + b) % 10;
}

int product_loop(int n) {
    int product = 1;
    for (int j = 1; j <= 50; j++) {
        product *= add_mod(n, j);
    }
    return product;
}

int main() {
    int product = 1;
    for (int i = 1; i <= 100; i++) {
        product *= product_loop(i);
    }
    printf("Product: %d\n", product);
    return 0;
}
