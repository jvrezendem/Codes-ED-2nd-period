#include <iostream>
#include <cstdlib>

using namespace std;

class No {
    friend class Pilha;
    private:
        int numeroNo; //dado armazenado no nó
        No* proximoNo; //ponteiro que aponta para o proximo nó
    public:
        No(int numero) { // construtor
            proximoNo = NULL; //aponta o ponteiro para NULL 
            numeroNo = numero; //inicialaiza o nó com o valor inserido
        }

        int getNumroNo(){
            return numeroNo; //retorna o valor de um nó
        }
};

//Pilha = principio First in Last out "FILO"
//Exemplo de estrutura dinânica, ou seja, não possui tamanho definido
class Pilha {
    private:
        unsigned tamanhoPilha;
        No* ponteiroTopo; //aponta para o topo da pilha => caracteristica da estrutura de pilha ter apenas um ponteiro

        void limparPilha(){ //função usada no destrutor => retirar todos os nós da pilha
            while(!isEmpty()){
                desempilha();
            }
        }
    public:
        Pilha(){
            this->ponteiroTopo = NULL; //inicializa o topo como NULL pois ainda não há elementos
            this->tamanhoPilha = 0;
        }

        ~Pilha(){
            limparPilha();
        }

        unsigned getTamanho() {
            return this->tamanhoPilha;
        }

        void empilha(int numero) {
            //cria um novo nó com o valor inserido
            No* novoNo = new No(numero);

            //aponta o ponteiro do próximo nó para o topo, no caso de ser o primeiro nó, vai apontar para NULL
            novoNo->proximoNo = this->ponteiroTopo;

            //aponta o ponteiro do topo para o próximo nó
            this->ponteiroTopo = novoNo;

            //incrementa o tamanho da pilha
            this->tamanhoPilha++;
        }

        int desempilha(){

            //criação de um nó auxiliar para utilizar o valor do nó desempilhado
            No* aux = this->ponteiroTopo;

            //valor contido no nó
            int numeroNo = aux->getNumroNo();

            //aponta o ponteiro do topo para o proximo nó (nó abaixo do que vai ser retirado)
            this->ponteiroTopo = aux->proximoNo;

            //deleta a memória utilizada pelo nó desempilhado
            delete aux;

            //decrementa o tamanho da pilha
            this->tamanhoPilha--;

            return numeroNo;
        }

        //verifica se a pilha está vazia
        bool isEmpty(){
            /*
            if(this->tamanhoPilha == 0) {
                return true;
            }
            return false;
            */
            return (ponteiroTopo == NULL);
        }
};

int main(){
    //criar objeto pilha
    Pilha pilha;

    int numeroAdicionar;
    cin >> numeroAdicionar;

    //empilha elementos não negativos na pilha
    while (numeroAdicionar >= 0) {
        pilha.empilha(numeroAdicionar);
        cin >> numeroAdicionar;
    }

    cout << "Tamanho da pilha: " << pilha.getTamanho() << endl;

    cout << "Elementos da pilha (sendo desempilhados)" << endl;

    //mostra os valores desempilhados 
    while (!pilha.isEmpty()){
        cout << pilha.desempilha() << " ";
    }
    cout << endl;
    
    return 0;
}