#include <stdio.h>

int main() {
    int product = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 50; j++) {
            product *= (i + j) % 10;
        }
    }
    printf("Product: %d\n", product);
    return 0;
}
