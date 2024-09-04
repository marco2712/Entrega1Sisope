#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    // Check if the character is an uppercase letter
    if (ch >= 'A' && ch <= 'Z') {
        printf("%c is an uppercase letter.\n", ch);
    } else {
        printf("%c is not an uppercase letter.\n", ch);
    }

    return 0;
}
