#include <iostream>

using namespace std;

class No{

    friend class Fila;

    private:
        int conteudoNo;
        No* ponteiroProximoNo;
    public:
        No(int valorInserido){
            conteudoNo = valorInserido;
            ponteiroProximoNo = NULL;
        }
};

class Fila {
    private:
        No* ponteiroInicio;
        No* ponteiroFim;
        unsigned tamanhoFila;
    public:
        Fila(){
            ponteiroInicio = NULL;
            ponteiroFim = NULL;
            tamanhoFila = 0;
        }

        ~Fila(){
            while (!isEmpy())
                desenfileira();
        }

        bool isEmpy(){
            if(tamanhoFila == 0) return true;
            return false;
        }

        void enfileira(int valorInserido){
            No* novoNo = new No(valorInserido);
            if(isEmpy()){
                ponteiroInicio = novoNo;
            }else{
                ponteiroFim->ponteiroProximoNo = novoNo;
            }
            ponteiroFim = novoNo;
            tamanhoFila++;
        }

        int desenfileira(){
           No* aux = ponteiroInicio;
           int dadoNo = aux->conteudoNo;
           ponteiroInicio = aux->ponteiroProximoNo;
           delete aux;
           tamanhoFila--;
           if(isEmpy()){
            ponteiroFim = NULL;
           } 
           return dadoNo;
        }

        unsigned getTamanho(){
            return tamanhoFila;
        }

        int spyInicio(){
            int valor = ponteiroInicio->conteudoNo;
            return valor;
        }


};

int main() {

    Fila f1, f2, f3;
    int inserirValor, tam1, tam2;
    int ultimo1 = 0, ultimo2 = 0;

    cin >> tam1;
    for(int i = 0; i < tam1; i++){
        cin >> inserirValor;
        if(inserirValor != ultimo1)
            f1.enfileira(inserirValor);
        ultimo1 = inserirValor;
    }

    cin >> tam2;
    for(int i = 0; i < tam2; i++){
        cin >> inserirValor;
        if(inserirValor != ultimo2)
            f2.enfileira(inserirValor);
        ultimo2 = inserirValor;
    }

    while(!f1.isEmpy() and !f2.isEmpy()){

        bool flag = true;
        
        int elemento1 = f1.spyInicio();
        int elemento2 = f2.spyInicio();

        if(elemento1 == elemento2){
            
            f3.enfileira(elemento1);
            f1.desenfileira();
            f2.desenfileira();
        
        }else{
            if(elemento1 < elemento2){
                f3.enfileira(elemento1);
                f1.desenfileira();
            }
            if(elemento1 > elemento2){
                f3.enfileira(elemento2);
                f2.desenfileira();

            }
        }
    }

    while(!f1.isEmpy()){
        f3.enfileira(f1.desenfileira());
    }
    while(!f2.isEmpy()){
        f3.enfileira(f2.desenfileira());
    }

    int tam3 = f3.getTamanho();
    for(int i = 0; i < tam3; i++){
        cout << f3.desenfileira() << " ";
    }
    cout << endl;

    
    return 0;
}