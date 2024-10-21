#include <stdio.h>
#include <string.h>

void modify_string(char *str, int i) {
    for (int j = 0; j < strlen(str); j++) {
        str[j] = (str[j] + i) % 128;
    }
}

int main() {
    char str[100] = "Lorem ipsum dolor sit amet";
    for (int i = 0; i < 10; i++) {
        modify_string(str, i);
    }
    printf("Modified string: %s\n", str);
    return 0;
}
