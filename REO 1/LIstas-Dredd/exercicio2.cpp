#include <iostream>

using namespace std;

class No {
    friend class Pilha;
    private:
        int valorNo;
        No* ponteiroProximoNo;
    public:
    No(int valor) {
        valorNo = valor;
        ponteiroProximoNo = NULL;
    }

    int getValorNo(){
        return valorNo;
    }
};

class Pilha {

    private:
        No* ponteiroTopo;
        unsigned tamanhoPilha;

        void limparPilha(){
            while(!isEmpty()){
                desempilha();
            }
        }
    public:
        //construtor da pilha
        Pilha(){
            ponteiroTopo = NULL;
            tamanhoPilha = 0;
        }

        //destrutor da pilha
        ~Pilha(){
            limparPilha();
        }

        unsigned getTamanho(){
            return tamanhoPilha;
        }

        bool isEmpty(){
            if(tamanhoPilha == 0){
                return true;
            }
            return false;
        }

        void empilha(int valorNo){
            No* novoNo = new No(valorNo);
            novoNo->ponteiroProximoNo = this->ponteiroTopo;
            this->ponteiroTopo = novoNo;
            this->tamanhoPilha++;
        }

        int desempilha(){
            No* aux = this->ponteiroTopo;
            int valorNo = aux->getValorNo();
            this->ponteiroTopo = aux->ponteiroProximoNo;
            delete aux;
            this->tamanhoPilha--;
            return valorNo;
        }

        int menor(Pilha& aux){
            int menor = desempilha();
            while(tamanhoPilha > 0){
                int pivo = desempilha();
                if(pivo < menor){
                    menor = pivo;
                }else{
                    aux.empilha(pivo);
                }
            }
            return menor;
        }

};


int main() {
    Pilha pilha1, pilha2;
    int tamanhoPilha, numeroAdicionar;
    cin >> tamanhoPilha;
    for(int i = 0; i < tamanhoPilha; i++){
        cin >> numeroAdicionar;
        pilha1.empilha(numeroAdicionar);
    }

    cout << "Tamanho da pilha: " << pilha1.getTamanho() << endl;
    cout << "Menor elemento: " << pilha1.menor(pilha2) << endl;

    cout << "Tamanho da pilha: " << pilha1.getTamanho() << endl;
    cout << "Tamanho da pilha: " << pilha2.getTamanho() << endl;
    return 0;
}