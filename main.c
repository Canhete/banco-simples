/* CONTA BANCÁRIA

    INCLUIR NUMEROS E SALDO

    SUPORTE AS OPERAÇÕES:
        - INICIAR NOVA CONTA COM UM NUMERO E SALDO
        - DEPOSITAR UM VALOR NA CONTA
        - SACAR UM VALOR DA CONTA
        - IMPRIMIR SALDO
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int cont = 0;

typedef struct {
    int numero;
    char saldo[100];
} conta;

void criarConta(conta *C){
    float valorReal;
    char valorFormatado[100];

    printf("Digite o número da conta: ");
    scanf("%d", &C->numero);
    getchar();

    printf("Digite o saldo da conta: ");
    scanf("%f", &valorReal);

    snprintf(valorFormatado, sizeof(valorFormatado), "%.2f R$", valorReal);
    strcpy(C->saldo, valorFormatado);
}

void depositarValor(conta *C){
    float valorDeposito;
    char valorFormatado[100];
    float valorSaldo = atof(C->saldo);

    printf("Digite o valor a ser depositado: ");
    scanf("%f", &valorDeposito);

    valorSaldo += valorDeposito;

    snprintf(valorFormatado, sizeof(valorFormatado), "%.2f R$", valorSaldo);
    strcpy(C->saldo, valorFormatado);
}

void sacarValor(conta *C){
    float valorSaque;
    char valorFormatado[100];
    float valorSaldo = atof(C->saldo);

    printf("Digite o valor a ser sacado: ");
    scanf("%f", &valorSaque);

    valorSaldo -= valorSaque;

    snprintf(valorFormatado, sizeof(valorFormatado), "%.2f R$", valorSaldo);
    strcpy(C->saldo, valorFormatado);
}

void mostrarSaldo(conta *C){
    printf("############################################\n");
    printf("Número da conta: %d\n", C->numero);
    printf("Saldo atual: %s\n", C->saldo);
    printf("############################################\n");
}

int main(void){
    conta *Contas = malloc(sizeof(conta));

    int n;
    do {
        printf("Escolha uma opção:\n");
        printf("[1] -> INICIAR NOVA CONTA COM UM NUMERO E SALDO\n");
        printf("[2] -> DEPOSITAR UM VALOR NA CONTA\n");
        printf("[3] -> SACAR UM VALOR DA CONTA\n");
        printf("[4] -> IMPRIMIR SALDO\n");
        printf("[0] -> SAIR\n");
        printf("> ");
        scanf("%d", &n);
        getchar();

        switch (n){
        case 1:
            criarConta(Contas);
            break;
        
        case 2:
            depositarValor(Contas);
            break;
        
        case 3:
            sacarValor(Contas);
            break;

        case 4:
            mostrarSaldo(Contas);
            break;

        case 0:
            break;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (n!=0);

    return 0;
}