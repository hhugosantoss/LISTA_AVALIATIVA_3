#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main() {
    
    int tempo;
        double valorInvestido;
        double Juros;
    

    scanf("%d", &tempo);
    scanf("%lf", &valorInvestido);
    scanf("%lf", &Juros);

    for (int i = 1; i <= tempo; i++) {
        double soma = 1 + Juros;
        double valorinvestido = valorInvestido * soma * (pow(soma, i) - 1) / Juros;
        printf("Montante ao fim do mes %d: R$ %0.2lf\n", i, valorinvestido);
    }

    return 0;
}
