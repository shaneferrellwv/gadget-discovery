#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 10; k++) {
                fprintf(file, "Line %d-%d-%d\n", i, j, k);
            }
        }
    }
    fclose(file);
    return 0;
}
