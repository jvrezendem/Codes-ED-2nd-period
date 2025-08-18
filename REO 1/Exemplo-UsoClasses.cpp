#include <iostream>
#include <cstdlib>

using namespace std;

class vectorx {
    private:
        int tam;
        int* vetor;
    public:
        //construtores e destrutor
        vectorx() {
            vetor = new int[10];
            tam = 10;
        };

        vectorx(int n) {
            vetor = new int[n];
            tam = n;
        };
        ~vectorx() {
            cout << "Objeto Finalizado!"<< endl;
            delete[] vetor;
            tam = 0;
        };

        //metodos
        void preenche() {
            for(int i = 0; i < tam; i++) {
                vetor[i] = rand() % 100;
            }
        }

        void imprime() {
            for(int i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
        }

        void concatena(vectorx& vec1, vectorx& vec2) {
            for(int i = 0; i < vec1.tam; i++){
                vetor[i] = vec1.vetor[i];
            }

            for(int i = 0; i < vec2.tam; i++) {
                vetor[i+vec1.tam] = vec2.vetor[i];
            }
        }

        int getTam() {
            int contador = 0;
            for(int i = 0; i <= tam; i++){
                contador++;
            }

            return contador;
        }

};

int main() {

    srand(time(NULL));
    int tam1, tam2;

    cin >> tam1 >> tam2;

    vectorx teste;
    vectorx vec1(tam1);
    vectorx vec2(tam2);

    vectorx vec3;
    vec3 = (tam1 + tam2);
    vectorx *ptrVecx;
    ptrVecx = new vectorx(17);

    //preenche os dados
    vec1.preenche();
    vec2.preenche();

    teste.preenche();
    ptrVecx->preenche();

    //concatenação
    vec3.concatena(vec1, vec2);

    // imprime os vetores
    cout << "Vetor teste" << endl;
    teste.imprime();
    cout << "Vetor ptrVecx" << endl;
    ptrVecx->imprime();
    cout << "Vetor vec1" << endl;
    vec1.imprime();
    cout << "Vetor vec2" << endl;
    vec2.imprime();
    cout << "Vetor vec3" << endl;
    vec3.imprime();

    delete ptrVecx;

    return 0;
}