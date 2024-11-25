#include <stdio.h>

void versao1(float salario) {
    float reservaTrabalhador, reservaImpostos, descontoIRPF, descontoINSS;

    reservaTrabalhador = salario * 0.08;
    reservaImpostos = salario * 0.03;

    if (salario <= 2112.00) {
        descontoIRPF = 0.0;
    } else if (salario <= 2826.65) {
        descontoIRPF = (salario - 2112.00) * 0.075;
    } else if (salario <= 3751.05) {
        descontoIRPF = (salario - 2826.65) * 0.15 + (714.0 * 0.075);
    } else if (salario <= 4664.68) {
        descontoIRPF = (salario - 3751.05) * 0.225 + (714.0 * 0.075) + (924.35 * 0.15);
    } else {
        descontoIRPF = (salario - 4664.68) * 0.275 + (714.0 * 0.075) + (924.35 * 0.15) + (913.63 * 0.225);
    }

    descontoINSS = salario * 0.075;

    printf("Reserva mensal para pagamentos dos direitos do trabalhador: R$ %.2f\n", reservaTrabalhador);
    printf("Reserva mensal para pagamentos de impostos e multas: R$ %.2f\n", reservaImpostos);
    printf("Desconto do IRPF: R$ %.2f\n", descontoIRPF);
    printf("Desconto do INSS: R$ %.2f\n", descontoINSS);
}

void versao2(float salario) {
    float reservaTrabalhador, reservaImpostos, descontoIRPF, descontoINSS, impostoSistemaS;

    reservaTrabalhador = salario * 0.08;
    reservaImpostos = salario * 0.03;

    if (salario <= 2112.00) {
        descontoIRPF = 0.0;
    } else if (salario <= 2826.65) {
        descontoIRPF = (salario - 2112.00) * 0.075;
    } else if (salario <= 3751.05) {
        descontoIRPF = (salario - 2826.65) * 0.15 + (714.0 * 0.075);
    } else if (salario <= 4664.68) {
        descontoIRPF = (salario - 3751.05) * 0.225 + (714.0 * 0.075) + (924.35 * 0.15);
    } else {
        descontoIRPF = (salario - 4664.68) * 0.275 + (714.0 * 0.075) + (924.35 * 0.15) + (913.63 * 0.225);
    }

    descontoINSS = salario * 0.075;
    impostoSistemaS = salario * 0.02;

    printf("Reserva mensal para pagamentos dos direitos do trabalhador: R$ %.2f\n", reservaTrabalhador);
    printf("Reserva mensal para pagamentos de impostos e multas: R$ %.2f\n", reservaImpostos);
    printf("Desconto do IRPF: R$ %.2f\n", descontoIRPF);
    printf("Desconto do INSS: R$ %.2f\n", descontoINSS);
    printf("Impostos e taxas pagos pelo Sistema S: R$ %.2f\n", impostoSistemaS);
}

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
            printf("O seu imposto de renda é: R$ %.2f e o INSS é: R$ %.2f, seu salário líquido é: R$ %.2f\n", Imposto1, Imposto2, Bruto - (Imposto1 + Imposto2));
        } else {
            Bruto = S2 + T;
            printf("Você está livre de imposto de renda, porém seu INSS é: R$ %.2f, logo seu salário líquido é: R$ %.2f\n", Imposto2, (Bruto - Imposto2));
        }

        printf("\nEscolha a versão da folha de pagamento:\n");
        printf("1. Versão 1\n");
        printf("2. Versão 2\n");
        printf("Digite sua escolha (1 ou 2): ");
        int escolha;
        scanf("%d", &escolha);

        if (escolha == 1) {
            versao1(Bruto);
        } else if (escolha == 2) {
            versao2(Bruto);
        } else {
            printf("Escolha inválida.\n");
        }
    }

    return 0;
}

