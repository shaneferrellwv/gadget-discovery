#include <stdio.h>

int square(int n) {
    return n * n;
}

int main() {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += square(i);
    }
    printf("Sum: %d\n", sum);
    return 0;
}
