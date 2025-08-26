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
            f2.enfileira(auxF2);
        }

        if(flag){
            f1.enfileira(elemento);
        }
    }

    while(!f1.isEmpy()){
        cout << f1.desenfileira() << " ";
    }
    cout << endl;

    return 0;
}