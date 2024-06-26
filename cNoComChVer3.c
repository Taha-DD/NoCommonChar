#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void noSameSame(char *str, char *letr) {
    char *temp, save;
    while (temp = strpbrk(str, letr)) {
        save = *temp;
        while (temp = strchr(letr, save)) {
            *temp++ = '\0';
            memmove( letr + strlen( letr ), temp, strlen( temp ) + 1 );
        }
        
        while (temp = strchr(str, save)) {
            *temp++ = '\0';
            memmove( str + strlen( str ), temp, strlen( temp ) + 1 );
        }
    }
}

int main() {
    char str[400];
    char letter[400];
    
    printf("O'hello there home town\nEnter the first string: ");
    gets(str);
    
    printf("Now enter the second string: ");
    gets(letter);
    
    noSameSame(str, letter);
    
    printf("Those two without the common letters: %s %s\n", str, letter);
    
    if (strlen(str) == 0 && strlen(letter) == 0)
        printf("See, they don't exist, just like your... ahem ahem.\n");
    
    return 0;
}