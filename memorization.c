#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int precos[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int *memo;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calcularReceitaMaximaDP(int n) {
    if (n <= 0) return 0;
    if (memo[n] != -1) return memo[n];
    
    int receitaMax = INT_MIN;
    for (int i = 1; i <= n && i <= 10; i++) {
        receitaMax = max(receitaMax, precos[i-1] + calcularReceitaMaximaDP(n - i));
    }
    
    memo[n] = receitaMax;
    return receitaMax;
}

int main() {
    int n_max = 25;
    
    printf("=== RECEITAS MÁXIMAS DE 1 ATÉ %d ===\n", n_max);
    
    memo = (int*)malloc((n_max + 1) * sizeof(int));
    for (int j = 0; j <= n_max; j++) memo[j] = -1;
    
    // Cabeçalho
    printf("┌───────┬───────────────┐\n");
    printf("│   n   │ Receita Máxima │\n");
    printf("├───────┼───────────────┤\n");
    
    for (int n = 1; n <= n_max; n++) {
        int receita = calcularReceitaMaximaDP(n);
        printf("│ %5d │ %13d │\n", n, receita);
    }
    
    printf("└───────┴───────────────┘\n");
    
    free(memo);
    return 0;
}