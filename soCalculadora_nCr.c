#include <stdio.h>

long long fatorial(int n) {
    if (n == 0) return 1;
    long long fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

long long combinacao(int n, int r) {
    return fatorial(n) / (fatorial(r) * fatorial(n - r));
}

int main() {
    int n, r;
    
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    printf("Digite o valor de r: ");
    scanf("%d", &r);
    
    if (r > n) {
        printf("r nao pode ser maior que n.\n");
        return 1;
    }
    
    printf("nCr = %lld\n", combinacao(n, r));
    
    return 0;
}
