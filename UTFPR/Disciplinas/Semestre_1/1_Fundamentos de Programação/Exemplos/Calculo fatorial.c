int fatorial (int n){
    int i, f = 1;

    for(i = n; i > 1; i--){
        f = f * i;
    }

    return f;
}


int f;
f = fatorial(5);