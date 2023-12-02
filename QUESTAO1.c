#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char numRomano[13];
    scanf("%s", numRomano);

    // Verifica se o número romano é válido
    int len = strlen(numRomano);
    bool valido = true;
    for (int i = 0; i < len; i++) {
        char c = numRomano[i];
        if (c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M') {
            valido = false;
            break;
        }
    }

   

    // Converte número romano para decimal
    int resultado = 0;
    for (int i = 0; i < len; i++) {
        int valorAtual;
        switch (numRomano[i]) {
            case 'I': valorAtual = 1; break;
            case 'V': valorAtual = 5; break;
            case 'X': valorAtual = 10; break;
            case 'L': valorAtual = 50; break;
            case 'C': valorAtual = 100; break;
            case 'D': valorAtual = 500; break;
            case 'M': valorAtual = 1000; break;
            default: valorAtual = 0; break;
        }

        int proximoValor = (i < len - 1) ? (
            (numRomano[i + 1] == 'I') ? 1 :
            (numRomano[i + 1] == 'V') ? 5 :
            (numRomano[i + 1] == 'X') ? 10 :
            (numRomano[i + 1] == 'L') ? 50 :
            (numRomano[i + 1] == 'C') ? 100 :
            (numRomano[i + 1] == 'D') ? 500 :
            (numRomano[i + 1] == 'M') ? 1000 :
            0
        ) : 0;

        if (valorAtual < proximoValor) {
            resultado += proximoValor - valorAtual;
            i++;
        } else {
            resultado += valorAtual;
        }
    }

    // Converte decimal para binário
    long binario = 0, fator = 1;
    int temp = resultado;
    while (temp > 0) {
        binario += (temp % 2) * fator;
        temp /= 2;
        fator *= 10;
    }

    // Imprime os resultados
    printf("%s na base 2: %ld\n", numRomano, binario);
    printf("%s na base 10: %d\n", numRomano, resultado);
    printf("%s na base 16: %x\n", numRomano, resultado);

    return 0;
}
