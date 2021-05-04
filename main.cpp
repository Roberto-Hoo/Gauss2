#include <iostream>

using namespace std;

bool imprime = true;

int N = 3;
int ind = 0;

double **A = nullptr;
double *b = nullptr;
double *x = nullptr; //


/*
 * Retorna um número aleatorio inteiro entre minimo e o maximo(inclusive os extremos)
 */

void eliminacaoGauss(int ind,  double **&A, double *&b) {
    double aux1 = A[ind][ind];
    if (imprime)
        printf("A[%d][%d] = %6.2f", ind, ind, A[ind][ind]);
    for (int i = ind + 1; i < N; i++) {
        if (abs(A[i][ind]) > 1e-14) {
            double aux2 = A[i][ind];
            for (int j = 0; j < N; j++) {
                A[i][j] = A[i][j] - A[ind][j] * aux2 / aux1;
            }
            b[i] = b[i] - b[ind] * aux2 / aux1;
        }
    }
}

void imprimeMatriz_Ab(char *nome, double **&A, double *&b) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %10.5f ", A[i][j]);
        }
        printf("    %10.5f\n", b[i]);
    }
}


/*
 * Retorna um número aleatorio inteiro entre minimo e o maximo(inclusive os extremos)
 */
int numeroAleatorio(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}



int main() {


    //srand((unsigned) time(0)); //para gerar números aleatórios reais.
    srand(1); //Para gerar os mesmos numeros.

    A = new double *[N];
    b = new double[N];
    x = new double[N];


    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        b[i] = (double) numeroAleatorio(1, 10);
        for (int j = 0; j < N; j++) {
            A[i][j] = (double) numeroAleatorio(1, 10);
        }
    }

    imprimeMatriz_Ab("Matriz A e b",A,b);

    eliminacaoGauss(ind, A, b);

    imprimeMatriz_Ab("Matriz A e b",A,b);
    ind++;
    eliminacaoGauss(ind, A, b);

    imprimeMatriz_Ab("Matriz A e b",A,b);

    for (int i = N - 1; i > -1; i--) {
        double soma = 0.0;
        for (int j = i; j < N-1 ; j++)
            soma += x[j+1] * A[i][j+1];
        x[i] = (b[i] - soma) / A[i][i];
        printf("x[%d] = %12.10f ",i,x[i] );
    }

   
    return 0;
}

