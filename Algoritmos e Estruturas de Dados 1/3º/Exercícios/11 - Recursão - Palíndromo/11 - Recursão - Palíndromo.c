#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int palindromo(char str[], int ini, int fim){
    if (fim <= ini)
        return 1;
    else if (str[ini] != str[fim])
        return 0;
    else
        return palindromo(str, ini + 1, fim - 1);
}

int main() {
    char str[50];
    
    scanf("%s", str);
    
    if (palindromo(str, 0, strlen(str) - 1))
        printf("palindromo");
    else
        printf("nao palindromo");
  
    return 0;
}