#include <iostream>
#include <cstdlib>

using namespace std;

class No {
    friend class Pilha;
    private:
        int numeroNo;
        No* proximoNo;
    public:
        No(int numero) {
            proximoNo = NULL;
            numeroNo = numero;
        }

        int getNumroNo(){
            return numeroNo;
        }
};

class Pilha {
    private:
        unsigned tamanhoPilha;
        No* ponteiroTopo;

        void limparPilha(){
            while(!isEmpty()){
                desempilha();
            }
        }
    public:
        Pilha(){
            ponteiroTopo = NULL;
            tamanhoPilha = 0;
        }

        ~Pilha(){
            limparPilha();
        }

        unsigned getTamanho() {
            return tamanhoPilha;
        }

        void empilha(int numero) {
            No* novoNo = new No(numero);
            novoNo->proximoNo = this->ponteiroTopo;
            this->ponteiroTopo = novoNo;
            this->tamanhoPilha++;
        }

        int desempilha(){
            No* aux = this->ponteiroTopo;
            int numeroNo = aux->getNumroNo();
            this->ponteiroTopo = aux->proximoNo;
            delete aux;
            this->tamanhoPilha--;
            return numeroNo;
        }

        bool isEmpty(){
            if(tamanhoPilha == 0) {
                return true;
            }
            return false;
        }
};

int main(){
    //criar objeto pilha
    Pilha pilha;

    int numeroAdicionar;
    cin >> numeroAdicionar;

    while (numeroAdicionar >= 0) {
        pilha.empilha(numeroAdicionar);
        cin >> numeroAdicionar;
    }

    cout << "Tamanho da pilha: " << pilha.getTamanho() << endl;

    cout << "Elementos da pilha, (sendo desempilhados)" << endl;

    while (!pilha.isEmpty()){
        cout << pilha.desempilha() << " ";
    }
    cout << endl;
    
    
    return 0;
}