#include <stdio.h>

int main() {
    float S1, S2, S4, T, Bruto, InRenda = 0.024, INSS = 0.015, Min = 2424.00, Imposto1, Imposto2;
    int Anos;
    char op, op1;

    printf("Me diga seu salário: ");
    scanf("%f", &S1);

    if (S1 < 1400.00) {
        printf("O valor é inválido.\n");
    } else {
        printf("Qual sua formação? 1 - Doutor, 2 - Mestre, 3 - Especialista: ");
        scanf(" %c", &op);

        switch (op) {
            case '1':
                S2 = S1 + (S1 * 0.60);
                printf("O salário + a formação é: R$ %.2f\n", S2);
                break;
            case '2':
                S2 = S1 + (S1 * 0.40);
                printf("O salário + a formação é: R$ %.2f\n", S2);
                break;
            case '3':
                S2 = S1 + (S1 * 0.20);
                printf("O salário + a formação é: R$ %.2f\n", S2);
                break;
            default:
                printf("Operador inválido.\n");
                return 1;
        }

        printf("Me fale o seu tempo de contribuição (em anos): ");
        scanf("%d", &Anos);

        T = S2 * (Anos * 0.01);
        printf("O valor do seu salário com o tempo de contribuição é: R$ %.2f\n", (S2 + T));

        printf("Você tem direito ao Auxílio? (S/N): ");
        scanf(" %c", &op1);

        switch (op1) {
            case 'S':
                S4 = S2 + (T + 440);
                printf("O valor do Auxílio é 440 + o salário: R$ %.2f\n", S4);
                break;
            case 'N':
                printf("O valor do Salário bruto é: R$ %.2f\n", (S2 + T));
                break;
            default:
                printf("Operador inválido.\n");
                return 1;
        }

        if (S2 + T > Min) {
            Bruto = S2 + T;
            Imposto1 = (Bruto - Min) * InRenda;
            Imposto2 = Bruto * INSS;
            printf("O seu imposto de renda é R$ %.2f e o INSS é R$ %.2f. Seu salário líquido é R$ %.2f\n", Imposto1, Imposto2, Bruto - (Imposto1 + Imposto2));
        } else {
            Bruto = S2 + T;
            Imposto2 = Bruto * INSS;
            printf("Você está livre de imposto de renda, porém seu INSS é R$ %.2f. Logo, seu salário líquido é R$ %.2f\n", Imposto2, (Bruto - Imposto2));
        }
    }

    return 0;
}
