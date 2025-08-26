#include <iostream>

using namespace std;

class No {
    friend class Fila;
    private:
        int valorNo;
        No* ponteiroProximoNo;
    public: 
        No(int valorInserido){
            this->valorNo = valorInserido;
            this->ponteiroProximoNo = NULL;
        }
};

class Fila {
    private:
        No* ponteiroInicio;
        No* ponteiroFim;
        unsigned tamanhoFila;
    public:
        //construtor da fila
        Fila(){
            ponteiroInicio = NULL;
            ponteiroFim = NULL;
            tamanhoFila = 0;    
        }

        //destrutor
        ~Fila(){
            while(!isEmpy()){
                desenfileira();
            }
        }

        void enfileira(int valorInserido){
            No* novoNo = new No(valorInserido);
            if(isEmpy()) {
                this->ponteiroInicio = novoNo;
            }else{
                this->ponteiroFim->ponteiroProximoNo = novoNo;
            }
            this->ponteiroFim = novoNo;
            this->tamanhoFila++;
        }

        int desenfileira(){
            int valorNo = this->ponteiroInicio->valorNo;
            No* temp = this->ponteiroInicio;
            this->ponteiroInicio =  this->ponteiroInicio->ponteiroProximoNo;
            delete temp;
            this->tamanhoFila--;
            if(isEmpy()){
                this->ponteiroFim = NULL;
            }
            return valorNo;
        }

        bool isEmpy(){
            if(this->tamanhoFila == 0) return true;
            return false;
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

    cout << "tamanho: " << fila.getTamanho() << endl;; 
    while(!fila.isEmpy()){
        cout << "Desenfileirando: " << fila.desenfileira() << endl;
    }



    return 0;
}