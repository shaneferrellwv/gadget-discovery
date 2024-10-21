#include <stdio.h>

void write_line(FILE *file, int i, int j, int k) {
    fprintf(file, "Line %d-%d-%d\n", i, j, k);
}

int main() {
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 10; k++) {
                write_line(file, i, j, k);
            }
        }
    }
    fclose(file);
    return 0;
}
