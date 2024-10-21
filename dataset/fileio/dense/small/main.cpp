#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < 10; i++) {
        fprintf(file, "Line %d\n", i);
    }
    fclose(file);
    return 0;
}
