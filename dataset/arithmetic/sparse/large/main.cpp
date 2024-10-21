#include <stdio.h>

long long mod_mult(int a, int b, int c) {
    return (a * b * c) % 100;
}

long long sum_loop(int n, int m) {
    long long sum = 0;
    for (int k = 1; k <= 100; k++) {
        sum += mod_mult(n, m, k);
    }
    return sum;
}

int main() {
    long long sum = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 500; j++) {
            sum += sum_loop(i, j);
        }
    }
    printf("Sum: %lld\n", sum);
    return 0;
}
