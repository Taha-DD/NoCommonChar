#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void noSameSame(char *str, char *letr) {
    char *temp, save, gard[400];
    while (temp = strpbrk(str, letr)) {
        save = *temp;
        while (temp = strchr(letr, save)) {
            *temp = '\0';
            strcpy(gard, temp + 1);
            strcat(letr, gard);
        }
        
        while (temp = strchr(str, save)) {
            *temp = '\0';
            strcpy(gard, temp + 1);
            strcat(str, gard);
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