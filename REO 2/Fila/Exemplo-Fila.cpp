#include <iostream>

using namespace std;

class No {
    friend class Fila;
    private:
        //valor contido no nó
        int valorNo;
        //ponteiro que aponta para o proximo nó
        No* ponteiroProximoNo;
    public: 
        No(int valorInserido){
            this->valorNo = valorInserido; //iicia o nó com o valor a ser inserido 
            this->ponteiroProximoNo = NULL; //aponta para o NULL o ponteiro para o próximo nó
        }
};

//Fila = Principio First in First out "FIFO"
//Exemplo de estrutura dinâmica
class Fila {
    private:
        //caracteristica da fila, ter dois ponteiros, um que aponta para o inicio da estrutura e outro que aponta para o final
        No* ponteiroInicio; //ponteiro que aponta pra o inicio
        No* ponteiroFim; //ponteiro que aponta pra o final
        unsigned tamanhoFila; //tamanho da fila
    public:
        //construtor da fila
        Fila(){
            ponteiroInicio = NULL;
            ponteiroFim = NULL;
            tamanhoFila = 0;    
        }

        //destrutor
        ~Fila(){
            while(!isEmpy()){ //desenfileira todos os elementos
                desenfileira();
            }
        }

        void enfileira(int valorInserido){

            No* novoNo = new No(valorInserido); //cria um novo nó com o valor inserido
            if(isEmpy()) { //verifica se a fila está vazia
                this->ponteiroInicio = novoNo; //se estiver aponta o ponteiro do inicio para o nó criado
            }else{
                //se não estiver aponta o ponteiro do proximo nó do atual fim (que antes apontava para NULL) para o nó criado
                this->ponteiroFim->ponteiroProximoNo = novoNo; 
            }
            this->ponteiroFim = novoNo; //aponta o ponteiro do final para o nó criado
            this->tamanhoFila++;
        }

        int desenfileira(){

            //armazena o valor do nó que está sendo apontado pelo ponteiro do inicio
            int valorNo = this->ponteiroInicio->valorNo; 

            //cria um nó temporario que recebe o nó que etá sendo apontado pelo ponteiro do inicio
            No* temp = this->ponteiroInicio; 

            //aponta o ponteiro do inicio para o próximo nó após o inicio (na segunda posição da fila, logo ele se torna o primeiro da fila)
            this->ponteiroInicio =  this->ponteiroInicio->ponteiroProximoNo; 

            //deleta o nó temporario
            delete temp;

            //decrementa o tamanho da fila
            this->tamanhoFila--;

            if(isEmpy()){//verifica se a fila está vazia
                this->ponteiroFim = NULL;//se estiver, aponta o ponteiro do fim para NULL
            }
            return valorNo;
        }

        bool isEmpy(){
            return (this->ponteiroInicio == NULL);
        }

        unsigned getTamanho(){
            return tamanhoFila;
        }
};

int main(){
    Fila fila;
    int elemento;
    cin >> elemento;

    while(elemento >= 0){
        fila.enfileira(elemento);
        cin >> elemento;
    }

    cout << "tamanho: " << fila.getTamanho() << endl; 
    while(!fila.isEmpy()){
        cout << "Desenfileirando: " << fila.desenfileira() << endl;
        cout << "tamanho: " << fila.getTamanho() << endl; 
    }

    return 0;
}