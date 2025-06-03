#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int main() {
    int formapagamento, parcelamento, abastecimento, litrosAbastecidos;
    char respostapagamento[4], respostaabastecimento;
    float valorAbastecimento;
    SYSTEMTIME st;
    GetLocalTime(&st);
    setlocale(LC_ALL, "Portuguese");

    char encerrar = ' ';
    while (encerrar != 'S' && encerrar != 's') {
        formapagamento = 0;
        respostapagamento[0] = '\0';
        int escolhaValida = 0;

        while (!escolhaValida) {
            printf("Ol�! Seja bem-vindo ao posto Ipiranga\n\n");

            printf("Indique a forma de pagamento, as op��es s�o:\nDigite 1 caso seja Dinheiro. \nDigite 2 caso seja Pix. \nDigite 3 caso seja Cart�o de cr�dito. \n");
            scanf("%d", &formapagamento);

            switch (formapagamento) {
                case 1:
                    printf("\nProcessando...\n\n");
                    Sleep(3);
                    printf("Voc� escolheu Dinheiro. A op��o est� correta? (sim / n�o): ");
                    break;
                case 2:
                    printf("\nProcessando...\n\n");
                    Sleep(3);
                    printf("Voc� escolheu Pix. A op��o est� correta? (sim / n�o): ");
                    break;
                case 3:
                    printf("\nProcessando...\n\n");
                    Sleep(3);
                    printf("Voc� escolheu Cart�o de cr�dito. A op��o est� correta? (sim / n�o): ");
                    break;
                default:
                    printf("\nProcessando...\n\n");
                    Sleep(3);
                    printf("Op��o inv�lida. Por favor, escolha novamente.\n");
                    while(getchar() != '\n');
                    continue;
            }

            scanf("%s", respostapagamento);

            if (respostapagamento[0] == 's' || respostapagamento[0] == 'S') {
                printf("\n�timo! Voc� escolheu a op��o %d.\n\n", formapagamento);
                if (formapagamento == 3) {
                    printf("J� que a op��o selecionada foi Cart�o de cr�dito, oferecemos o parcelamento em at� tr�s vezes. Em quantas vezes deseja parcelar? (1, 2 ou 3): ");
                    scanf("%d", &parcelamento);
                    printf("Ok, voc� escolheu parcelar em %d vezes\n", parcelamento);
                    Sleep(1);
                }
                escolhaValida = 1;
            } else {
                printf("\nPor favor, escolha novamente a forma de pagamento.\n\n");
            }
        }

        while (1) {
            printf("Agora que j� foi informada a forma de pagamento, voc� deseja abastecer por um valor espec�fico ou por uma determinada quantidade de litros?\n Digite 1 para abastecer por um valor espec�fico. \nDigite 2 para abastecer por uma determinada quantidade de litros\n");
            scanf("%d", &abastecimento);

            switch (abastecimento) {
                case 1:
                    printf("\nProcessando...\n\n");
                    Sleep(3);
                    printf("Voc� escolheu abastecer por um valor espec�fico. A op��o est� correta? (sim/n�o): ");
                    break;
                case 2:
                    printf("\nProcessando...\n\n");
                    Sleep(3);
                    printf("Voc� escolheu abastecer por uma determinada quantidade de litros. A op��o est� correta? (sim/n�o): ");
                    break;
                default:
                    printf("\nProcessando...\n\n");
                    Sleep(3);
                    printf("Op��o inv�lida. Por favor, escolha novamente.\n");
                    continue;
            }

            scanf(" %c", &respostaabastecimento);

            if (respostaabastecimento == 's' || respostaabastecimento == 'S') {
                printf("\nPerfeito! Voc� escolheu abastecer da forma desejada.\n\n");

                if (abastecimento == 1) {
                    printf("Digite o valor em dinheiro que gostaria de abastecer: \n");
                    scanf("%f", &valorAbastecimento);
                    printf("Abastecimento de R$%.2f realizado com sucesso!\n", valorAbastecimento);
                    litrosAbastecidos = 0;
                } else {
                    printf("Digite a quantidade de litros que gostaria de abastecer: ");
                    scanf("%d", &litrosAbastecidos);
                    printf("Abastecimento de %d litros realizado com sucesso!\n", litrosAbastecidos);
                    valorAbastecimento = 0.0;
                }

                FILE *relatorio = fopen("relat�rio.txt", "a");

                if (relatorio != NULL) {
                    fprintf(relatorio, "Forma de pagamento: %d\n", formapagamento);
                    if (abastecimento == 1) {
                        fprintf(relatorio, "Abastecimento por valor espec�fico: R$%.2f\n", valorAbastecimento);
                    } else {
                        fprintf(relatorio, "Abastecimento por quantidade de litros: %d litros\n", litrosAbastecidos);
                    }
                    fprintf(relatorio, "Data e hora do atendimento: %02d/%02d/%d -- %02d:%02d\n", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute);
                    fprintf(relatorio, "------------------------------------\n");
                    fclose(relatorio);
                } else {
                    printf("Erro ao abrir o arquivo de relat�rio.\n");
                }

                printf("Deseja encerrar o atendimento? (Digite 'S' para sair, qualquer outra tecla para continuar): ");
                scanf(" %c", &encerrar);
                if (encerrar == 'S' || encerrar == 's') {
                    printf("Atendimento encerrado. Obrigado!\n");
                    break;
                } else {
                    
                    formapagamento = 0;
                    respostapagamento[0] = '\0';
                    escolhaValida = 0;
                    break; 
                }
            } else {
                printf("Por favor, escolha novamente a forma de abastecimento.\n");
            }
        }
    }
    return 0;
}

