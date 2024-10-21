#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] + 1;
    }
    printf("Modified string: %s\n", str);
    return 0;
}
