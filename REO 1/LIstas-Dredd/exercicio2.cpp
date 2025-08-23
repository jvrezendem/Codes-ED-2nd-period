#include <iostream>

using namespace std;

class No
{
    friend class Pilha;

private:
    int valorNo;
    No *ponteiroProximoNo;

public:
    No(int valor)
    {
        valorNo = valor;
        ponteiroProximoNo = NULL;
    }

    int getValorNo()
    {
        return valorNo;
    }
};

class Pilha
{

private:
    No *ponteiroTopo;
    unsigned tamanhoPilha;

    void limparPilha()
    {
        while (!isEmpty())
        {
            desempilha();
        }
    }

public:
    // construtor da pilha
    Pilha()
    {
        ponteiroTopo = NULL;
        tamanhoPilha = 0;
    }

    // destrutor da pilha
    ~Pilha()
    {
        limparPilha();
    }

    unsigned getTamanho()
    {
        return tamanhoPilha;
    }

    bool isEmpty()
    {
        if (tamanhoPilha == 0)
        {
            return true;
        }
        return false;
    }

    void empilha(int valorNo)
    {
        No *novoNo = new No(valorNo);
        novoNo->ponteiroProximoNo = this->ponteiroTopo;
        this->ponteiroTopo = novoNo;
        this->tamanhoPilha++;
    }

    int desempilha()
    {
        No *aux = this->ponteiroTopo;
        int valorNo = aux->valorNo;
        this->ponteiroTopo = aux->ponteiroProximoNo;
        delete aux;
        this->tamanhoPilha--;
        return valorNo;
    }

    int spyTop()
    {
        int valorNoTopo = this->ponteiroTopo->valorNo;
        return valorNoTopo;
    }

    void sortPilha(Pilha &pilhaAux)
    {
        // Passo 1: move da original -> auxiliar, inserindo em ordem (crescente; topo = menor)
        while (!this->isEmpty())
        {
            int x = this->desempilha(); // pega um elemento da original

            // Enquanto a auxiliar tiver elementos MAIORES que x,
            // devolve-os para a original para abrir espaço
            while (!pilhaAux.isEmpty() && pilhaAux.spyTop() > x)
            {
                this->empilha(pilhaAux.desempilha());
            }

            // Agora x está na posição correta da ordenada (auxiliar)
            pilhaAux.empilha(x);
        }

        // Passo 2: traz de volta da auxiliar -> original para deixar o resultado em 'this'
        while (!pilhaAux.isEmpty())
        {
            this->empilha(pilhaAux.desempilha());
        }
    }
};

int main()
{
    Pilha pilha1, pilha2;
    int tamanhoPilha, numeroAdicionar;
    cin >> tamanhoPilha;
    for (int i = 0; i < tamanhoPilha; i++)
    {
        cin >> numeroAdicionar;
        pilha1.empilha(numeroAdicionar);
    }

    pilha1.sortPilha(pilha2);

    for (int i = 0; i < tamanhoPilha; i++)
    {
        cout << pilha1.desempilha() << " ";
    }
    cout << endl;
    return 0;
}