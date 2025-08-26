/*
    Dadas duas filas F1 e F2, implemente o método que remove os elementos de F2, presentes em F1. F1 deve estar disponível após a remoção dos elementos de F2 para outras operações. As propriedades de fila devem ser estritamente respeitadas, ou seja: não é permitido o acesso aleatório aos elementos da fila.A fila deve ser implementada utilizando encadeamento.

Entradas:

Número de elementos a serem inseridos em F1.
Elementos de F1 em ordem de inserção (inserção no fim da fila).
Número de elementos a serem inseridos em F2.
Elementos de F2 em ordem de inserção (inserção no fim da fila).
Saídas:

Elementos restantes em F1 após a remoção.
Exemplo de Entrada:

11

4 6 9 10 1 9 2 13 7 3 5

4

9 2 7 3
Exemplo de Saída:

4 6 10 1 13 5
*/

#include <iostream>

using namespace std;

class No {
    friend class Fila;
    private:
        int conteudoNo;
        No* ponteiroProximoNo;
    public:
        No(int valorInserido){
            this->conteudoNo = valorInserido;
            this->ponteiroProximoNo = NULL;
        }
};

class Fila {
    private:
        No* ponteiroFim;
        No* ponteiroInicio;
        unsigned tamanhoFila;
    public:
        Fila(){
            ponteiroFim = NULL;
            ponteiroInicio = NULL;
            tamanhoFila = 0;
        }

        ~Fila(){
            while(!isEmpy()){
                desenfileira();
            }
        }

        bool isEmpy(){
            if(tamanhoFila == 0) return true;
            return false;
        }

        void enfileira(int valorInserido) {
            No* novoNo = new No(valorInserido);
            if(isEmpy()){
                this->ponteiroInicio = novoNo;
            }else{
                this->ponteiroFim->ponteiroProximoNo = novoNo;
            }
            this->ponteiroFim = novoNo;
            this->tamanhoFila++;
        }

        int desenfileira() {
            No* aux = ponteiroInicio;
            int dadoNo = aux->conteudoNo;
            this->ponteiroInicio = aux->ponteiroProximoNo;
            delete aux;
            this->tamanhoFila--;
            if(isEmpy()){
                this->ponteiroFim = NULL;
            }
            return dadoNo;
        }  
};

int main(){

    Fila f1, f2;
    int tam1, tam2;
    int valor;

    //recebe os dados de f1
    cin >> tam1;
    for(int i = 0; i < tam1; i++){
        cin >> valor;
        f1.enfileira(valor);
    }

    //recebe os dados de f2
    cin >> tam2;
    for(int i = 0; i < tam2; i++){
        cin >> valor;
        f2.enfileira(valor);
    }

    //passa por todos os elemento de f1
    for(int i = 0; i < tam1; i++) {

        bool flag = true;

        //pega o primeiro elemento para analise
        int elemento = f1.desenfileira();
        
        for(int i = 0; i < tam2 and flag; i++){
            int auxF2 = f2.desenfileira();
            //se for encontrado algum elemento igual em f1 e f2
            if(elemento == auxF2){
                flag = false;
            }
            //retorna o elemento para o final da fila
            f2.enfileira(auxF2);
        }

        //se não for encontrado elemento igual, ele é retornado para f1
        if(flag){
            f1.enfileira(elemento);
        }
    }

    //desempilha e imprime os elementos de f1 com as alterações
    while(!f1.isEmpy()){
        cout << f1.desenfileira() << " ";
    }
    cout << endl;

    return 0;
}