#include "circulo.h"
#include <stdlib.h>
//#include <stdio.h>

struct circulo{
    tPonto centro;
    float r;
};

/**
 * @brief Retorna um circulo com centro nas coordenadas (x,y) e raio r
 * @param x Posição x do centro do círculo
 * @param y Posição y do centro do círculo
 * @param r Raio do Círculo
 * @return Ponteiro para a estrutura tCirculo criada 
 */
tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo circulo = (tCirculo) malloc (sizeof(struct circulo));

    tPonto ponto = Pto_Cria(x, y);
    Circulo_Atribui_Centro(circulo, ponto);

    Circulo_Atribui_Raio(circulo, r);
    return circulo;
}

/**
 * @brief Libera a memória alocada pelo círculo
 * @param c Variável do tipo tCírculo que será apagada.
 */
void Circulo_Apaga (tCirculo c){
    Pto_Apaga(c->centro);
    free(c);
}

/**
 * @brief Retorna o ponto que representa o centro do circulo
 * @param c Círculo que terá o seu centro retornado
 * @return Variável do tipo ponto que representa o centro de "c"
 */
tPonto Circulo_Acessa_Centro (tCirculo c){
    return c->centro;
}

/**
 * @brief Funcao que acessa o raio do círculo
 * @param c Círculo que terá o seu raio retornado
 * @return o raio do círculo
 */
float Circulo_Acessa_Raio (tCirculo c){
    return c->r;
}

/**
 * @brief Funcao que atribui um novo centro para um círculo
 * @param c Círculo que terá o seu centro atualizado
 * @param p Ponto que representará o novo centro do círculo
 */
void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    c->centro = p;
}

/**
 * @brief Funcao que atribui um novo raio para um círculo
 * @param c Círculo que terá o seu raio atualizado
 * @param r Novo raio do círculo
 */
void Circulo_Atribui_Raio (tCirculo c, float r){
    c->r = r;
}

/**
 * @brief Funcao que indica se um ponto p está dentro do círculo c.
 * @param c Círculo que será acessado e comparado com o ponto
 * @param p Novo raio do círculo
 * @return Uma variável inteira com valor zero se o ponto p estiver fora do círculo, e 1 caso contrário.
 */
int Circulo_Interior (tCirculo c, tPonto p){

    double distancia = Pto_Distancia(Circulo_Acessa_Centro(c), p);

    // Verifica se a distância é menor ou igual ao raio do círculo
    if (distancia <= Circulo_Acessa_Raio(c)) {
        return 1; // Ponto está dentro do círculo
    } else {
        return 0; // Ponto está fora do círculo
    }
}