#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *strtolower ( char *str ) {
    char *st = ( char* ) malloc ( strlen( str ) + 1 );
    strcpy( st, str );
    for ( char *s = st; *s; ++s )
        *s = tolower( *s );
    return st;
}

void noSameSame ( char *str, char *letr ) {
    char *temp, save[2] = { '\0', '\0'};
    
    while ( temp = strpbrk( strtolower(str), strtolower(letr) ) ) {
        save[0] = *temp;
        temp = strtok( strtolower(str), save );
        if ( !temp ) {
            *str = *letr = '\0';
            break;
        }
        strcpy( str, temp );
        while ( temp ) {
            temp = strtok( NULL, save );
            if ( temp )
                strcat( str, temp );
        }
        temp = strtok( strtolower(letr), save );
        strcpy( letr, temp );
        while ( temp ) {
            temp = strtok( NULL, save );
            if ( temp )
                strcat( letr, temp );
        }
    }
    
}

int main()
{
    char *str = ( char* ) malloc ( 400 ),
      *letter = ( char* ) malloc ( 400 );
    printf(" O'hello there home town\n enter first string: ");
    gets(str);
    printf(" now the second: ");
    gets(letter);
    
    noSameSame( str, letter );
    
    printf(" those two without the common letters: %s %s", str, letter);
    if ( !*str && !*letter )
        printf(" see they don't exist just like your... ahm ahm");
    
    return 0;
}