#include <iostream>

using namespace std;

int * insertion_sort_reverse(int* input, int n) {
	
	int key, j = 0;

	for (int i=n-2; i >= 0; --i) {

		key = input[i];
		j = i + 1;

		while (j < n && key < input[j]) {
			input[j - 1] = input[j];
			j++;
		}

		input[j - 1] = key;
	}	

	return input;
}

int main() {
	
	int n=0, in;

	printf("Digite o tamanho do array: ");
	scanf("%d", &n);

	int* input = new int[n];

	for(int i=0; i < n; i++) {
	
		scanf("%d", &in);
		input[i] = in;
	
	}

	insertion_sort_reverse(input, n);
	
	for (int i=0; i < n; i++) {
		
		printf("%d  ", input[i]);

	}

	printf("\n");

	delete[] input;

	return 0;
}
