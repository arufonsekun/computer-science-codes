#include <iostream>
#include <stdio.h>
#include <string>
#include <array>
using namespace std;

array<int, 26> repetitions;

int checkRep(string a) {
	unsigned short int repeat = 0;
	for (int i = 0; i < a.size(); i++){
		if (repetitions.at(a[i] -'a') >= 0){
			repetitions.at(a[i] - 'a') += 1;
			repeat++;
		}
	}
	return repeat;
}



int main(){
	string input;
	cin >> input;
	if (checkRep(input) == input.size()){
		cout << input.size() -1;
	};
	for (int i = 0; i < repetitions.size(); i++){
		cout << repetitions[i] << ' ';
	}
	cout << endl;


	return 0;
}
