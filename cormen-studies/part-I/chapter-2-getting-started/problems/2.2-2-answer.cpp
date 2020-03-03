#include <iostream>
using namespace std;

void INSERTION_SORT(int A[], int length){

	int key, i;

    for(int j = 2; j < length; j++){
        
		key = A[j];
        i = j - 1;
        
		while (i > 0 and A[i] < key){
            A[i + 1] = A[i];
            i = i - 1;
		}
        A[i + 1] = key;
	}
}

int main() {
	
	int length = 5;
	int A[] = {3,2,1,5,8};
	INSERTION_SORT(A, length);

	for (int i=0; i < length; i++) {
	
		cout << A[i] << "  ";

	}

	cout << endl;

	return 0;
}
