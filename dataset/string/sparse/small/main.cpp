#include <stdio.h>
#include <string.h>

void modify_char(char *c) {
    *c = *c + 1;
}

int main() {
    char str[] = "Hello, World!";
    for (int i = 0; i < strlen(str); i++) {
        modify_char(&str[i]);
    }
    printf("Modified string: %s\n", str);
    return 0;
}
