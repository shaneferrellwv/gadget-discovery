#include <stdio.h>

void write_line(FILE *file, int i) {
    fprintf(file, "Line %d\n", i);
}

int main() {
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < 10; i++) {
        write_line(file, i);
    }
    fclose(file);
    return 0;
}
