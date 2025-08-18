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

//struct é uma classe onde tudo é publico
struct vectorx
{
    int* vetor;
    int tam;

    void inicializa(int n) {
        vetor = new int[n];
        tam = n;
    }

    void finaliza() {
        delete[] vetor;
        tam = 0;
    }

    //preencher o vetor com dados aleatórios
    void preencher() {
        for(int i = 0; i < tam; i++) {
            vetor[i] = rand() % 100;
        }
    }

    //concatena 2 vetores, vec1 e vec2 em vec
    void concatena(vectorx& vec1, vectorx& vec2) {
        int tam1 = vec1.tam;
        int tam2 = vec2.tam;

        for(int i = 0; i < tam1; i++){
            vetor[i] = vec1.vetor[i];
        }

        for(int i= 0; i < tam2; i++){
            vetor[i+tam1] = vec2.vetor[i];
        }
    }

    void imprime() {
        for(int i = 0; i < tam; i++) {
            cout << vetor[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    vectorx vec1, vec2, vec3;
    int tam1, tam2;

    cin >> tam1 >> tam2;

    //seed de geração de numeros
    srand(time(NULL));

    vec1.inicializa(tam1);
    vec2.inicializa(tam2);
    vec3.inicializa(tam1+tam2);

    vec1.preencher();
    vec2.preencher();
    vec3.concatena(vec1, vec2);

    vec1.imprime();
    vec2.imprime();
    vec3.imprime();

    vec1.finaliza();
    vec2.finaliza();
    vec3.finaliza();

    return 0;
}



