#include <stdio.h>
#include <stdlib.h>

int precos[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

// Função para retornar o maior valor de um array
int RetornaOMaiorValor(int valores[], int tamanho) {
    if (valores == NULL || tamanho <= 0) {
        printf("Parâmetros inválidos!\n");
        return -1;
    }
    
    int maior = valores[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (valores[i] > maior) {
            maior = valores[i];
        }
    }
    return maior;
}

// Função para calcular receita máxima (corrigida)
int calcularReceitaMaxima(int n) {
    if (n <= 0) return 0;
    if (n == 1) return precos[0];
    
    int *r = (int*)malloc(n * sizeof(int));
    if (r == NULL) return -1;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            r[i] = precos[n-1]; // Vender como peça única
        } else {
            // Vender como duas peças: tamanho i e tamanho n-i
            r[i] = calcularReceitaMaxima(i) + calcularReceitaMaxima(n - i);
        }
    }
    
    int receitaMax = RetornaOMaiorValor(r, n);
    free(r);
    return receitaMax;
}

int main() {
    printf("=== Teste da Função calcularReceitaMaxima ===\n\n");
    
    // Testes para diferentes tamanhos de haste
    int testes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_testes = sizeof(testes) / sizeof(testes[0]);
    
    printf("Tabela de Preços: [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]\n");
    printf("| Tamanho | Receita Máxima |\n");
    printf("|---------|----------------|\n");
    
    for (int i = 0; i < num_testes; i++) {
        int n = testes[i];
        int resultado = calcularReceitaMaxima(n);
        printf("| %7d | %14d |\n", n, resultado);
    }
    
    // Testes adicionais
    printf("\n=== Testes Adicionais ===\n");
    printf("Tamanho 0: %d\n", calcularReceitaMaxima(0));
    printf("Tamanho -1: %d\n", calcularReceitaMaxima(-1));
    
    return 0;
}