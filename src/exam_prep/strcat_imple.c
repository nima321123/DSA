#include <stdio.h>


void my_strcat(char *dest, char *src){

    /*Traverse to the end of the destination string*/
    while(*dest != '\0'){
        dest++;
    }
    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    // Add a null character at the end of the destination string
    *dest = '\0';
}

int main(){
    char dest[100] = "Hello ";
    char src[] = "World";
    my_strcat(dest, src);
    printf("%s", dest);
    return 0;
}