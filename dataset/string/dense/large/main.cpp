#include <stdio.h>
#include <string.h>

int main() {
    char str[1000] = "Lorem ipsum dolor sit amet...";
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < strlen(str); j++) {
            str[j] = (str[j] + i + j) % 128;
        }
    }
    printf("Modified string: %s\n", str);
    return 0;
}
