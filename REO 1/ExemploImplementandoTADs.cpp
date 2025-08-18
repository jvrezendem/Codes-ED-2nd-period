#include <iostream>
#include <cstdlib>

using namespace std;

//struct é um tipo abstrato de dado

/*
Aqui você passa apenas o endereço de memória do registro.

A função altera diretamente o original.

Não há cópia completa, só um ponteiro (mais leve).

É útil para modificar os dados originais e para economizar memória quando o registro é grande.
*/

/*
Por cópia → segurança (o original não muda), mas consome mais memória se o struct for grande.

Por ponteiro → eficiência e permite modificar o original, mas precisa cuidado com endereços inválidos.
*/
struct vectorx
{
    int* vetor;
    int tam;
};

// -> é usado quando você tem um ponteiro para struct e quer acessar um campo dela
void inicializa(vectorx* vec, int n) {
    vec->vetor = new int[n];
    vec->tam = n;

}

void finaliza(vectorx* vec) {
    delete[] vec->vetor;
    vec->tam = 0;
}

//preencher o vetor com dados aleatórios
void preencher(vectorx* vec) {
    for(int i = 0; i < vec->tam; i++) {
        vec->vetor[i] = rand() % 100;
    }
}

//concatena 2 vetores, vec1 e vec2 em vec
void concatena(vectorx* vec1, vectorx* vec2, vectorx* vec) {
    int tam1 = vec1->tam;
    int tam2 = vec2->tam;

    for(int i = 0; i < tam1; i++){
        vec->vetor[i] = vec1->vetor[i];
    }

    for(int i= 0; i < tam2; i++){
        vec->vetor[i+tam1] = vec2->vetor[i];
    }
}

void imprime(vectorx* vec) {
    for(int i = 0; i < vec->tam; i++) {
        cout << vec->vetor[i] << " ";
    }
    cout << endl;
}

int main(){
    vectorx vec1, vec2, vec3;
    int tam1, tam2;

    cin >> tam1 >> tam2;

    //seed de geração de numeros
    srand(time(NULL));

    inicializa(&vec1, tam1);
    inicializa(&vec2, tam2);
    inicializa(&vec3, tam1+tam2);

    preencher(&vec1);
    preencher(&vec2);
    concatena(&vec1, &vec2, &vec3);

    imprime(&vec1);
    imprime(&vec2);
    imprime(&vec3);

    finaliza(&vec1);
    finaliza(&vec2);
    finaliza(&vec3);

    return 0;
}



