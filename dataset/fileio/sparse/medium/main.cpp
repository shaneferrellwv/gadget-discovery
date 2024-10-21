#include <stdio.h>

void write_line(FILE *file, int i, int j) {
    fprintf(file, "Line %d-%d\n", i, j);
}

int main() {
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            write_line(file, i, j);
        }
    }
    fclose(file);
    return 0;
}
