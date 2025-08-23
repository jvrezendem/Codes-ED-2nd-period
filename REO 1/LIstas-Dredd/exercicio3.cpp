#include <iostream>

using namespace std;

class No {
    
    friend class Pilha;

    private:
        No* ponteiroProximoNo;
        char conteudoNo;
        unsigned posNo;
    public:
        //definar construtor
        No(char conteudo, unsigned pos){
            this->ponteiroProximoNo = NULL;
            this->conteudoNo = conteudo;
            this->posNo = pos;
        }

        unsigned getPos(){
            return posNo;
        }
};

class Pilha {
    private:
        No* ponteiroTopo;
        unsigned tamanhoPilha;
    public:

        Pilha(){
            ponteiroTopo = NULL;
            tamanhoPilha = 0;
        }

        ~Pilha() {
            while(!isEmpty()){
                desempilha();
            }
        }


        bool isEmpty(){
            if(tamanhoPilha == 0) return true;
            return false;
        }

        void empilha(char valorInserido, unsigned pos){
            No* novoNo = new No(valorInserido, pos);
            novoNo->ponteiroProximoNo = this->ponteiroTopo;
            this->ponteiroTopo = novoNo;
            this->tamanhoPilha++;
        }

        unsigned desempilha(){
            No* aux = this->ponteiroTopo;
            unsigned pos = aux->posNo;
            this->ponteiroTopo = aux->ponteiroProximoNo;
            delete aux;
            this->tamanhoPilha--;
            return pos;
        }

        unsigned getTamanhoPilha(){
            return tamanhoPilha;
        }



};

int main(){

    Pilha pilha;

    char texto[254];
    cin.getline(texto, 254);

    int i = 0;

    while(texto[i] != '\0') {

        if(texto[i] == '(') {
            pilha.empilha(texto[i], i);
        }

        if(texto[i] == ')') {
            if(pilha.isEmpty()){
                cout << i << endl;
                return 0;
            }else{
                pilha.desempilha();
            }
        }

        i++;
    }

    if(pilha.isEmpty()){
        cout << "correto" << endl;
    }else{
        cout << pilha.desempilha() << endl;
    }

    return 0;
}