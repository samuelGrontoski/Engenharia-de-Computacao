#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int * prog_arit(int n, int r){

    int *prog,a = 0, i;

    prog = malloc(n * (sizeof(int)));

    for(i = 0; i < n; i++){
        if(i == 0)
            prog[i] = a;
        else{
            a += r;
            prog[i] = a;
        }
    }

    return prog;

}

int main() {

    int n, r, *prog, i;

    scanf("%d %d", &n, &r);

    prog = prog_arit(n, r);

    for(i = 0; i < n; i++)
        printf("%d ", prog[i]);

    return 0;
}
