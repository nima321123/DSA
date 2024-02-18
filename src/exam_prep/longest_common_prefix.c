 #include <stdio.h>
 #include <stdlib.h>

 void getLCP(char* s1, char* s2, char* LCP)
 {
    while (*s1 == *s2){
       *LCP = *s1;
       LCP++;
       s1 ++;
       s2 ++;
    }
 }

 int main(){
    char s1[100], s2[100], lcp_string[100];
    scanf("%s %s", s1, s2);
    printf("Enter two strings: \n");
    getLCP(s1, s2, lcp_string);
    printf("\n%s", lcp_string);
    return 0;
 }