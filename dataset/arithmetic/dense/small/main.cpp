#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += i * i;
    }
    printf("Sum: %d\n", sum);
    return 0;
}
