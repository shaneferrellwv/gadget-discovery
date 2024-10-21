#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            fprintf(file, "Line %d-%d\n", i, j);
        }
    }
    fclose(file);
    return 0;
}
