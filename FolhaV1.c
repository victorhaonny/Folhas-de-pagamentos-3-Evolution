#include <stdio.h>

int main() {
    float Bruto, imposto1, imposto2;

    printf("Me diga seu salário bruto: ");
    scanf("%f", &Bruto);

    if (Bruto < 1400.0) {
        printf("Operador inválido\n");
    } else {
        if (Bruto <= 1302.00) {
            imposto2 = Bruto * 0.075;
        } else if (Bruto <= 2571.29) {
            imposto2 = (1302.00 * 0.075) + ((Bruto - 1302.00) * 0.09);
        } else if (Bruto <= 3856.94) {
            imposto2 = (1302.00 * 0.075) + (1269.29 * 0.09) + ((Bruto - 2571.29) * 0.12);
        } else if (Bruto <= 7507.49) {
            imposto2 = (1302.00 * 0.075) + (1269.29 * 0.09) + (1285.65 * 0.12) + ((Bruto - 3856.94) * 0.14);
        } else {
            imposto2 = (1302.00 * 0.075) + (1269.29 * 0.09) + (1285.65 * 0.12) + (3650.55 * 0.14);
        }

        printf("Desconto do Imposto 2: R$ %.2f\n", imposto2);

        if (Bruto <= 2112.00) {
            printf("Imposto zero\n");
            imposto1 = 0.0;
        } else if (Bruto <= 2826.65) {
            imposto1 = (Bruto - 2112.00) * 0.075;
            printf("Taxa de 7.5%% de Imposto 1: R$ %.2f\n", imposto1);
        } else if (Bruto <= 3751.05) {
            imposto1 = (Bruto - 2826.65) * 0.15 + (714.0 * 0.075);
            printf("Taxa de 15%% de Imposto 1: R$ %.2f\n", imposto1);
        } else if (Bruto <= 4664.68) {
            imposto1 = (Bruto - 3751.05) * 0.225 + (714.0 * 0.075) + (924.35 * 0.15);
            printf("Taxa de 22.5%% de Imposto 1: R$ %.2f\n", imposto1);
        } else {
            imposto1 = (Bruto - 4664.68) * 0.275 + (714.0 * 0.075) + (924.35 * 0.15) + (913.63 * 0.225);
            printf("Taxa de 27.5%% de Imposto 1: R$ %.2f\n", imposto1);
        }
    }

    return 0;
}
