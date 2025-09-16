/* Código base para estrutura de dados Fila
 * 
 * by Juliana Galvani Greghi
 *                                nov/2018
 */

#include <iostream>
#include <string>

using namespace std;

    class Noh {
        friend class Fila;
        private:
            string dado; // poderia ser outro tipo de variável
            Noh *proximo;
        public:
            Noh(string info){
                dado = info;
                proximo = NULL;
            }
    };

// fila dinamicamente encadeada
    class Fila {
    private:
        Noh* inicio;
        Noh* fim;
        int tamanho;
    
    public:
        Fila();
        ~Fila();
        void enfileira(string info);
        string desenfileira();
        bool estaVazia(); // verifica se existem elementos na fila     
};


Fila::Fila() {
    this->inicio = NULL;
    this->fim = NULL;
    this->tamanho = 0;
}

Fila::~Fila() { 
    while(!estaVazia()){
        desenfileira();
    }

}


void Fila::enfileira(string info) {
    Noh* novoNoh = new Noh(info);
    if(estaVazia()){
        this->inicio = novoNoh;
    }else{
        this->fim->proximo = novoNoh;
    }
    this->fim = novoNoh;
    this->tamanho++;
    
}

string Fila::desenfileira() {
    if(estaVazia()) return "";
    Noh* aux = this->inicio;
    string retorno = aux->dado;
    this->inicio = aux->proximo;
    delete aux;
    this->tamanho--;
    if(estaVazia()){
        this->fim = NULL;
    }
    return retorno;
}
    
bool Fila::estaVazia() {
    if(tamanho == 0) return true;
    return false;

}

int main() {
    bool flag = true;
    Fila filaPrioridade, filaNormal;
    int contadorAtendimento = 0;

    string prioridade, nome;
    int j = 0;
    while(flag){

        cin >> prioridade;

        if(prioridade == "fim"){
            flag = false;
        }

        if(prioridade == "normal"){
            cin >> nome;
            filaNormal.enfileira(nome);
        }

        if(prioridade == "prioridade"){
            cin >> nome;
            filaPrioridade.enfileira(nome);
        }

        if(prioridade == "atender"){

            if(filaPrioridade.estaVazia() and filaNormal.estaVazia()){
                cout << "AGUARDE" << endl;
            }

                if(contadorAtendimento < 3){
                    if(!filaPrioridade.estaVazia()){
                        cout << filaPrioridade.desenfileira() << endl;
                        contadorAtendimento++;
                    }else{
                        cout << filaNormal.desenfileira() << endl;
                        contadorAtendimento = 0;
                    }
                }else{
                    if(!filaNormal.estaVazia()) {
                        cout << filaNormal.desenfileira() << endl;
                        contadorAtendimento = 0;
                    }else{
                         cout << filaPrioridade.desenfileira() << endl;
                        contadorAtendimento = 1;
                    }
                }
        }
 
    }
    
}