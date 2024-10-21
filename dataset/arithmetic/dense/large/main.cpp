#include <stdio.h>

int main() {
    long long sum = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 500; j++) {
            for (int k = 1; k <= 100; k++) {
                sum += (i * j * k) % 100;
            }
        }
    }
    printf("Sum: %lld\n", sum);
    return 0;
}
