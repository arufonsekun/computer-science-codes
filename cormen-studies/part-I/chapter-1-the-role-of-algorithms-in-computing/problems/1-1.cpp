// Comparação de tempos de execução
// Para cada função f(n) e cada tempo t
// da tabela, determine o maior tamanho de n
// de um problema que pode ser resolvido no
// tempo t, considerando que o algoritmo para
// resolver o problema demore f(n) microssegundos

#include <iostream>
#include <cmath>

using namespace std;

void nLogn(int n) {
	
	float f_de_n = 0.0f;
	float i = 0;

	do
	{
		i+=10.25;
		f_de_n = i * log2(i);
		printf("\tf(%.2f) = %.2f\n", i, f_de_n);
	}
	while(f_de_n <= n);
}

int main() {

	// descobrir qual o tamanho de n para que f(n) = nlog2n compute-o em:
	// nLogn(100i0000); 1 segundo - aprox. 62746.13
	// nLogn(6*10e7); 1 minuto - aprox. 24446750.315
	// nLogn(36*10e8); // 1 hora
	
	return 0;
}


