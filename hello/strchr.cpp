#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *s = "0123456789012345678901234567890";
    char *p;
    p = strchr(s, '5');
    printf("%s\n", s);
    printf("%s\n", p);
    return 0;
}