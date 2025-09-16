#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef int dado;

class MaxHeap{
    private:
        dado* heap;
        int capacidade;
        int tamanho;
        //funções auxiliares
        inline int pai(int i);
        inline int esquerdo(int i);
        inline int direito(int i);
        void arruma(); //heapify
        void corrigeDescendo(int i);
        void corrigeSubindo(int i);
    public:
        MaxHeap(int cap); //construtor que constroi com uma capacidade definida
        MaxHeap(dado vet[], int tam); //construtor que altera os dados de um vetor para transformá-lo em um Heap
        ~MaxHeap();
        void imprime(); //apenas para funções didáticas
        dado espiaRaiz();
        dado retiraRaiz();
        void insere(dado d);
};

//declaração de funções de modo não inline
MaxHeap::MaxHeap(int tam){
    this->capacidade = tam;
    this->heap = new dado[tam];
    tamanho = 0;
}

MaxHeap::MaxHeap(dado vet[], int tam){
    this->capacidade = tam;

    this->heap = new dado[tam];

    //funcão que copia para um endereço de memória os dados de outro endereço de memoria
    memcpy(this->heap, vet, tam * sizeof(dado));

    this->tamanho = tam;
    //usa heapify para trasnformar o vetor em um heap
    this->arruma();

}

MaxHeap::~MaxHeap(){
    delete[] heap;
}

void MaxHeap::arruma(){
    for(int i = (tamanho/2)-1; i >= 0; i--){
        this->corrigeDescendo(i);
    }
}

int MaxHeap::pai(int i){
    return (i-1)/2;
}

int MaxHeap::esquerdo(int i){
    return 2*i+1;
}

int MaxHeap::direito(int i){
    return 2*i+2;
}


void MaxHeap::corrigeDescendo(int i){
    int esq = this->esquerdo(i);
    int dir = this->direito(i);
    int maior = i;

    //troca com o maior dos dois filhos

    if(esq < tamanho and heap[esq] > heap[maior]){
        maior = esq;
    }

    if(dir < tamanho and heap[dir] > heap[maior]){
        maior = dir;
    }

    if(maior != i) {
        swap(heap[i], heap[maior]);
        //funciona de forma recursiva até que encontre um nó folha
        corrigeDescendo(maior);
    }
}

void MaxHeap::corrigeSubindo(int i){
    int p = pai(i);

    //troca com o pai se o numero for maior que o pai
    if (heap[i] > heap[p]) {
        swap(heap[i], heap[p]);
        //funciona de forma recursiva até que encontre a raiz
        corrigeSubindo(p);
    }
}

void MaxHeap::imprime(){
    for(int i = 0; i < tamanho; i++){
        cout << this->heap[i] << " ";
    }
    cout << endl;
}

dado MaxHeap::espiaRaiz(){
    //a raiz se encontra sempre na primeira posição
    return this->heap[0];
}

dado MaxHeap::retiraRaiz(){
    //trata a exceção de heap vazio
    if(this->tamanho == 0){
        cerr << "Erro ao retirar raiz" << endl;
        exit(EXIT_FAILURE);
    }

    //armazena o dado da raiz
    dado aux = this->heap[0];
    swap(heap[0], heap[tamanho-1]);
    this->tamanho--;
    corrigeDescendo(0);
    return aux;

}

void MaxHeap::insere(dado d){
    if(this->tamanho == capacidade){
        cerr << "Erro ao inserir, heap sem capacidade" << endl;
        exit(EXIT_FAILURE);
    }
    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

int main(){
    int tam = 13;
    dado vet[] = {50, 2, 90, 20, 230, 43, 8, 34, 66, 100, 110, 3, 13};

    srand(time(NULL));

    MaxHeap *heap = new MaxHeap(vet, tam);
    MaxHeap *heap2 = new MaxHeap(tam);

    for(int i = 0; i < tam; i++){
        cout << heap->retiraRaiz() << " ";
    }
    cout << endl;

    for(int i = 0; i < tam; i++){
        heap2->insere(rand()%500);
    }

    for(int i = 0; i < tam; i++){
        cout << heap2->retiraRaiz() << " ";
    }
    cout << endl;

    delete heap;
    delete heap2;

    return 0;
}