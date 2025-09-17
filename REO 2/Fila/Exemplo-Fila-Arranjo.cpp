#include <iostream>

using namespace std;

//FilaCircular = Principio First in First out "FIFO"
//Exemplo de estrutura dinâmica
class FilaCircular {
    private:
        int inicio;
        int final;
        int *dados;
        unsigned capacidade;
        unsigned tamanhoFilaCircular; //tamanho da FilaCircular
    public:
        //construtor da FilaCircular
        FilaCircular(int cap = 10){
            this->inicio = -1;
            this->final = -1;
            this->capacidade = cap;
            this->dados = new int[this,capacidade];
            tamanhoFilaCircular = 0;    
        }

        //destrutor
        ~FilaCircular(){
           delete[] this->dados;
        }

        void enfileira(int valorInserido){
            //só enfileira se a fila tem capacidade para comportar mais elementos
            if(this->tamanhoFilaCircular < this->capacidade){
                //incrementa o fim, pois ele andara uma posição à frente
                this->final++;
                this->final = this->final % this->capacidade;
                //insere o novo elemento na nova posição
                this->dados[this->final] = valorInserido;

                //se a fila estiver vazia, incrementa o inicio
                if(this->tamanhoFilaCircular == 0){
                    this->inicio++;
                }
                this->tamanhoFilaCircular++;
            }else{
                cerr << "Fila cheia!" << endl;
            }
        }

        int desenfileira(){
            if(this->tamanhoFilaCircular > 0){
                int valor = this->dados[this->inicio];
                this->tamanhoFilaCircular--;
                if(this-> tamanhoFilaCircular > 0){
                    this->inicio++;
                    this->inicio = this->inicio % this->capacidade;
                }else{
                    this->inicio = -1;
                    this->final = -1;
                }

                return valor;

            }else{
                cerr << "Fila Vazia!" << endl;
                return -1;
            }
        }

        bool isEmpy(){
            return (tamanhoFilaCircular == 0);
        }

        unsigned getTamanho(){
            return tamanhoFilaCircular;
        }
};

int main(){
    FilaCircular fila(12);
    int elemento;
    for(int i = 0; i < 8; i++){
        cin >> elemento;
        fila.enfileira(elemento);   
    }
    cout << endl;

    cout << "tamanho: " << fila.getTamanho() << endl; 

    for(int i = 0; i < 5; i++){
        cout << "Desenfileirando: " << fila.desenfileira() << endl;
        cout << "tamanho: " << fila.getTamanho() << endl; 
    }
    cout << endl;

    for(int i = 0; i < 8; i++){
        cin >> elemento;
        fila.enfileira(elemento);   
    }
    cout << endl;
    
    cout << "tamanho: " << fila.getTamanho() << endl; 

    for(int i = 0; i < 5; i++){
        cout << "Desenfileirando: " << fila.desenfileira() << endl;
        cout << "tamanho: " << fila.getTamanho() << endl; 
    }
    cout << endl;

    return 0;
}