#include <iostream>

using namespace std;

class Noh{

    friend class ListaPos;

    private:
        int dado;
        int key;
        Noh* proximo;
    public:
        Noh(int valor, int key);
};

Noh::Noh(int valor, int key){
    this->dado = valor;
    this->key = key;
    this->proximo = NULL;
}

class ListaPos{
    private:
        Noh* inicio;
        void insereVazio(int valor, int key);
    public:
        ListaPos();
        void insereInicio(int valor, int key);
        bool listaVazia();
        bool busca(int chave);
        int buscaElemento(int chave);
};

ListaPos::ListaPos(){
    this->inicio = NULL;
}

void ListaPos::insereVazio(int valor, int key){
    Noh* novo = new Noh(valor, key);
    this->inicio = novo;

}

bool ListaPos::listaVazia(){
    return (this->inicio == NULL);
}

void ListaPos::insereInicio(int valor, int key){
    if(listaVazia()){
        insereVazio(valor, key);
    }else{
        Noh* novo = new Noh(valor, key);
        novo->proximo = this->inicio;
        this->inicio = novo;

    }
}

int ListaPos::buscaElemento(int chave){
    Noh* aux = this->inicio;
    while(aux != NULL){
        if(aux->key == chave){
            return aux->dado;
        }else{
            aux = aux->proximo;
        }
    }
    return -1;
}

class TabelaHash{
    private:
        unsigned tamanho;
        ListaPos* vetor;
    public:
        TabelaHash(int tamanho);
        ~TabelaHash();
        int hashFunction(int chave);
        void insereElemento(int valor, int chave);
        int recuperaValor(int chave);
};

TabelaHash::TabelaHash(int tamanho){
    this->tamanho = tamanho;
    this->vetor = new ListaPos[tamanho];

}

TabelaHash::~TabelaHash(){
    delete[] vetor;
}

void TabelaHash::insereElemento(int valor, int chave){
    int pos = hashFunction(chave);
    ListaPos& lista = vetor[pos];
    if(lista.buscaElemento(chave) == -1){
        lista.insereInicio(valor, chave);
    }else{
        cerr << "ERRO: item já cadastrado" << endl;
    }
}

int TabelaHash::recuperaValor(int chave){
    int pos = hashFunction(chave);
    int elemento = this->vetor[pos].buscaElemento(chave);
    if(vetor[pos].buscaElemento(chave) == -1){
        cerr << "ERRO: Elemento não encontrado!";
    }
    
    return elemento;
}

int TabelaHash::hashFunction(int chave){
    //função h(x) = k(mod n)
    return chave%this->tamanho;
}

int main(){
    int valorInserir;
    const int tamanhoTabela = 17;
    TabelaHash th(tamanhoTabela);
    cin >> valorInserir;
    while(valorInserir >= 0){
        int chave = valorInserir;
        th.insereElemento(valorInserir, chave);
        cin >> valorInserir;
    }

    int valorRecuperar;
    cout << "Insira valor a ser buscado: ";
    cin >> valorRecuperar;
    int chaveRecuperar = valorRecuperar;

    cout << "Retorno da tabela hash" << endl 
         << "Valor: " << th.recuperaValor(chaveRecuperar) << endl 
         << "Posiçao: " << th.hashFunction(chaveRecuperar) << endl;

    return 0;
}