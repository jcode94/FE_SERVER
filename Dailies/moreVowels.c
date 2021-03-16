#include <stdio.h>
#include <string.h>

int main() {
    char buffer[21];
    char* name;
    int hiLo = 0;

    scanf("%s", buffer);
    name = strdup(buffer);

    for (char c = *name; c != '\0'; c = *++name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            hiLo++;
        else
            hiLo--;
    }

    if (hiLo > 0) printf("%d", 1);
    else printf("%d", 0);

    return 0;
}