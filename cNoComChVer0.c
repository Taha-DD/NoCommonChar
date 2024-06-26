#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void noSameSame(char *str, char *letr) {
    char temp[400] = "", save[400] = "";
    for (char *s = str; *s; ++s) {
        if (strchr(letr, *s) == NULL) {
            strncat(temp, s, 1);
        }
    }
    for (char *l = letr; *l; ++l) {
        if (strchr(str, *l) == NULL) {
            strncat(save, l, 1);
        }
    }
    strcpy(str, temp);
    strcpy(letr, save);
}

int main() {
    char str[400], letter[400];
    
    printf("O'hello there home town\nEnter first string: ");
    gets(str);
    printf("Now the second: ");
    gets(letter);
    
    
    noSameSame(str, letter);
    
    printf("Those two without the common letters: %s %s", str, letter);
    
    return 0;
}