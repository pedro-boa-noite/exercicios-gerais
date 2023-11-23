#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "conta.h"
#include "usuario.h"

struct Conta{
    tUsuario* usuario;
    float saldo;
    int numero;
};

/**
 * @brief Cria uma nova conta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para a nova conta criada.
 */
tConta *CriaConta(){
    tConta* conta = calloc(1, sizeof(tConta));

    if(conta == NULL) exit(0);

    conta->usuario = CriaUsuario();

    return conta;
}

/**
 * @brief Desaloca a memória de uma conta.
 * 
 * @param conta Ponteiro para a conta a ser destruída.
 */
void DestroiConta(tConta *conta){
    if(conta != NULL){
        DestroiUsuario(conta->usuario);
        free(conta);
    }
}

/**
 * @brief Lê os dados de uma conta e do usuario atraves da entrada padrão.
 * 
 * @param conta Ponteiro para a conta a ser lida.
 */
void LeConta(tConta *conta){
    LeUsuario(conta->usuario);
    scanf("%d\n", &conta->numero);
}

/**
 * @brief Imprime os dados de uma conta e do proprietário.
 * 
 * @param conta Ponteiro para a conta a ser impressa.
 */
void ImprimeConta(tConta *conta){
    printf("Conta: %d\nSaldo: R$ %.2f\n", conta->numero, conta->saldo);
    ImprimeUsuario(conta->usuario);
}

/**
 * @brief Verifica se uma conta possui o numero especificado.
 * 
 * @param conta Ponteiro para a conta a ser verificada.
 * @param numero Número da conta a ser verificado.
 * @return 1 se a conta possui o número especificado, 0 caso contrário.
 */
int VerificaConta(tConta *conta, int numero){
    if(conta->numero == numero) return 1;
    return 0;
}

/**
 * @brief Realiza um saque em uma conta caso o saldo seja suficiente.
 * 
 * @param conta Ponteiro para a conta a ser sacada.
 * @param valor Valor a ser sacado.
 */
void SaqueConta(tConta *conta, float valor){
    if(conta->saldo >= valor) conta->saldo = conta->saldo - valor;
}

/**
 * @brief Realiza um depósito em uma conta.
 * 
 * @param conta Ponteiro para a conta a ser depositada.
 * @param valor Valor a ser depositado.
 */
void DepositoConta(tConta *conta, float valor){
    conta->saldo = conta->saldo + valor;
}

/**
 * @brief Realiza uma transferência entre duas contas, caso o saldo da conta de origem seja suficiente.
 * 
 * @param destino Ponteiro para a conta de destino.
 * @param origem Ponteiro para a conta de origem.
 * @param valor Valor a ser transferido.
*/
void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    if(origem->saldo >= valor){
        SaqueConta(origem, valor);
        DepositoConta(destino, valor); 
    }
}