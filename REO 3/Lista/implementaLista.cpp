#include <iostream>

using  namespace std;

class Noh{
    friend class Lista;
    private:
        int dado;
        Noh* proximo;
    public:
        Noh(int valor);
};

Noh::Noh(int valor){
    this->dado = valor;
    this->proximo = NULL;
}

class Lista{
    private:
        unsigned tamanho;
        Noh* inicio;
        Noh* fim;

        void insereVazio(int valor);
        //int removeInicio();
        //int removeFim();


    public:
        Lista();
        //~Lista();
        void percorre();
        //int busca();
        void insere(int valor, int pos);
        void insereInicio(int valor);
        void insereFim(int valor);
        //int remove();
        bool listaVazia();

};

Lista::Lista(){
    this->inicio = NULL;
    this->fim = NULL;
    tamanho = 0;
}

bool Lista::listaVazia(){
    return (this->inicio == NULL);
}

void Lista::insereVazio(int valor){
    Noh* novo = new Noh(valor);
    this->inicio = novo;
    this->fim = novo;
    tamanho++;
}

void Lista::insereInicio(int valor){
    if(listaVazia()) insereVazio(valor);
    else{
        Noh* novo = new Noh(valor);
        novo->proximo = this->inicio;
        this->inicio = novo;
        tamanho++;
    }
}

void Lista::insereFim(int valor){
    if(listaVazia()) insereVazio(valor);
    else{
        Noh* novo = new Noh(valor);
        this->fim->proximo = novo;
        this->fim = novo;
        tamanho++;        
    } 
}

void Lista::insere(int valor, int pos){
    if(listaVazia()) insereVazio(valor);
    else if(pos == 0) insereInicio(valor);
    else if(pos == tamanho-1) insereFim(valor);
    else if(pos < 0 or pos >= tamanho) cerr << "Posição impropria" << endl;
    else{
        Noh* novo = new Noh(valor);
        Noh* aux = inicio;
        int i_aux = 0;
        while(i_aux < pos-1){
            aux = aux->proximo;
            i_aux++;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        tamanho++;
    }
}
void Lista::percorre(){
    Noh* aux = inicio;
    while(aux != NULL){
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

int main(){
    int num;
    Lista ls;
    cin >> num;
    while(num >= 0){
        ls.insereFim(num);
        cin >> num;
    }

    ls.percorre();

    return 0;
}