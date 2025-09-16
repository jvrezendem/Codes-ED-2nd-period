#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef int dado;

const int INVALIDO = -1;

//torneio nada mais é um maxHeap que vai copiando o maior valor até a raiz

class Torneio{
    private:
        dado* heap;
        int capacidade;
        int tamanho;
        int inicioDados; //indica o primeiro nó folha da árvore
        //funções auxiliares
        inline int pai(int i);
        inline int esquerdo(int i);
        inline int direito(int i);
        void arruma(); //heapify
        void copiaMaior(int i);
        void copiaSubindo(int i);
    public:
        Torneio(int numFolhas); //construtor que constroi com uma capacidade definida pelo numero de folhas
        Torneio(dado vet[], int tam); //construtor que altera os dados de um vetor para transformá-lo em um Heap
        ~Torneio();
        void imprime(); //apenas para funções didáticas
        void insere(dado d);
};

//declaração de funções de modo não inline
Torneio::Torneio(int numFolhas){
    this->capacidade = 1;
    while (this->capacidade < numFolhas){
        this->capacidade *= 2;

        this->capacidade = this->capacidade - 1 + numFolhas;
        this->heap = new dado[capacidade];
        this->inicioDados = capacidade - numFolhas;

        cout << "Inicio Dados: " << this->inicioDados << endl;
        cout << "Capacidade: " << this->capacidade << endl;

        for(int i = 0; i < this->capacidade; i++){
            this->heap[i] = INVALIDO;
        }
    }


    
}

Torneio::Torneio(dado vet[], int tam){
    /*
        Determinando a capacidade, o numero de possíveis pais
        é uma potencia de 2 menos 1. Capacidade é o numero de
        possiveis pais mais tamanho do vetor. comecamos com 1
        pai e vamos dobrando a cada caso.
    */
   this->capacidade = 1;
   while(this->capacidade < tam){
    this->capacidade *= 2;
   }

   //potencia de 2 menos 1 mais tamanho do vetor
   this->capacidade = this->capacidade - 1 + tam;

   this->heap = new dado[capacidade];

   //pos do primeiro nó folha
   this->inicioDados = capacidade - tam;

   cout << "inicio Dados: " << this->inicioDados << endl;
   cout << "Capacidade: " << this->capacidade << endl;

   memcpy(&heap[inicioDados], vet, tam*sizeof(dado));

   this->tamanho = tam;

   this->arruma();

}

Torneio::~Torneio(){
    delete[] heap;
}

void Torneio::arruma(){
    //aplica recebeMaior na primeira metade dos elementos
    cout << "Arruma: " << this->inicioDados - 1 << endl;
    for(int i = this->inicioDados - 1; i  >= 0; i--){
        copiaMaior(i);
    }
}

int Torneio::pai(int i){
    return (i-1)/2;
}

int Torneio::esquerdo(int i){
    return 2*i+1;
}

int Torneio::direito(int i){
    return 2*i+2;
}

void Torneio::copiaMaior(int i){
    int esq = this->esquerdo(i);
    int dir = this->direito(i);

    cout << "i: " << i << "  e: " << esq << "  d: " << dir << endl;
    int maior = INVALIDO;
    //verifica se o filho a esquerda existe
    if(esq < this->capacidade){
        //verifica se o filho a direita existe e se ele é maior que o filho a esquerda
        if(dir < this->capacidade and this->heap[dir] > this->heap[esq]){
            maior = dir;
        }else{
            maior = esq;
        }
        this->heap[i] = this->heap[maior];
    }else{
        //caso não tenha filhos
        this->heap[i] = INVALIDO;
    }
}

void Torneio::copiaSubindo(int i){
    int p = this->pai(i);
    if(heap[i] > heap[p]){
        heap[p] = heap[i];
        copiaSubindo(p);
    }
}

void Torneio::imprime(){
    for(int i = 0; i < tamanho; i++){
        cout << this->heap[i] << " ";
    }
    cout << endl;
}

void Torneio::insere(dado d){
    if(this->tamanho == this->capacidade){
        cerr << "Erro ao inserir" << endl;
        exit(EXIT_FAILURE); 
    }

    heap[this->tamanho + this->inicioDados] = d;
    copiaSubindo(this->tamanho + this->inicioDados);
    this->tamanho++;
}

int main(){

    int tam = 9;
    dado vet1[] = {50, 2, 90, 20, 230, 43, 8, 34, 66};

    Torneio *t1 = new Torneio(vet1, tam);
    t1->imprime();
    delete t1;

    tam = 13;
    dado vet2[] = {50, 2, 90, 20, 230, 43, 8, 34, 66, 100, 110, 3, 13};

    t1 = new Torneio(vet2, tam);
    t1->imprime();
    delete t1;

    tam = 9;
    t1 = new Torneio(9);
    for(int i = 0; i < tam; i++){
        t1->insere(vet1[i]);
        t1->imprime();
    }

    delete t1;
    

    return 0;
}